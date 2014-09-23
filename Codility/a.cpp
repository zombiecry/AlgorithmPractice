#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include<queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

#include <algorithm>
int solution(vector<int> &A) {
	int n=A.size();
	sort(A.begin(),A.end());
	int maxGap=numeric_limits<int>::min();
	for (int i=0;i<n-1;i++){
		maxGap=max(maxGap,abs(A[i+1]-A[i])/2);
	}
	return maxGap;
}

int main (){
	vector <int> A(10,0,8,2,-1,12,113);
	
	cout<<solution(A);
	return 0;
}


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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		vector <int> c(m+n);
		vector <int> a(A,A+m);
		vector <int> b(B,B+n);

		merge(a.begin(),a.end(),b.begin(),b.end(),c.begin());
		n=m+n;
		if (n%2==0){
			int l=c[n/2-1];
			int r=c[n/2];
			return double(l+r)*0.5;
		}
		else{
			return c[n/2];
		}
	}
};

int main (){
	Solution *sol=new Solution;
	int A[]={1};
	int B[]={1};
	cout<<sol->findMedianSortedArrays(A,1,B,1)<<endl;
	return 0;
}
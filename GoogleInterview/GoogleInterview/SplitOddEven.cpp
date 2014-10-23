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
void Split(vector<int> &a){
	int n=a.size();
	int l=0;
	int r=n-1;
	while(l<r) {
		if (a[r]%2==1) {
			swap(a[l],a[r]);
			l++;
		}
		else r--;
	}
}
int main () {
	int aa[]={1,2,3,4,5,6};
	vector<int> a(aa,aa+sizeof(aa)/sizeof(aa[0]));
	Split(a);
	for(int i=0;i<a.size();i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
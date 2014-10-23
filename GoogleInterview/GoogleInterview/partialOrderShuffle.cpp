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
void Shuffle(vector<int> &a) {
	int n=a.size();
	for(int i=1;i<n;i++){
		if (i%2==0) {	//small
			if (a[i]>a[i-1]) swap(a[i],a[i-1]);
		}
		else{
			if (a[i]<a[i-1]) swap(a[i],a[i-1]);
		}
	}
}

int main(){
	int aa[]={1,2,3,4,5,6};
	vector<int> a(aa,aa+sizeof(aa)/sizeof(aa[0]));
	Shuffle(a);
	for(int i=0;i<a.size();i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
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

int main(){
	float a[]={1.2, 2.5, 9.3};
	float x=4;
	int n=sizeof(a)/sizeof(a[0]);
	int l=lower_bound(a,a+n,x)-a;
	if (l==0) cout<<a[l]<<endl;
	else {
		if (abs(x-a[l-1])<abs(x-a[l])){
			cout<<a[l-1]<<endl;
		}
		else cout<<a[l]<<endl;
	}
	return 0;
}
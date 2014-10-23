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
#if 1
ifstream fin("a.in");
ofstream fout("a.out");
#define cin fin
//#define cout fout
#endif
int N;
long long unsigned n,m;

int main(){
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>n;
		char last=-1;
		bool ok=true;
		int cnt=0;
		int maxn=0;
		int cc=0;
		int lc=-1;
		for(int j=0;j<n;j++){
			char ch;
			cin>>ch;
			
			if (last==-1) {
				cnt=0;
				cc=1;
				last=ch;
				continue;
			}
			if (ch==last) {
				cc++;
				continue;
			}
			if (ch==last+1){
				if (lc==-1) {
					cnt++;
					maxn=max(maxn,cnt);
					lc=cc;
					cc=1;
					last=ch;
					continue;
				}
				if (cc==lc){
					cnt++;
					maxn=max(maxn,cnt);
					cc=1;
					last=ch;
					continue;
				}
				if(cc>=lc) {
					cnt++;
					maxn=max(maxn,cnt);
				}
				lc=-1;
				cc=1;
				last=ch;
				cnt=0;
				maxn=max(maxn,cnt);
				continue;
			}
			//inter
			if(cc>=lc) {
				cnt++;
				maxn=max(maxn,cnt);
			}
			cc=1;
			last=ch;
			lc=-1;
			cnt=0;
		}
		if(cc>=lc) {
			cnt++;
		}
		maxn=max(maxn,cnt);
		if (maxn>=3){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}
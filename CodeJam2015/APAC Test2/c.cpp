#include <vector>
#include <set>
#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("c.in");
ofstream fout("c.out");
int T;
int m,n;
int x;
vector <int> a;
set    <int> s;
typedef pair<int,int>  scpair;
int INF;
int dp[1000001];

int Press(int y){
	int res=0;
	while(y){
		int di=y%10;
		if (s.find(di)==s.end()) return INF;
		res++;
		y/=10;
	}
	return res;
}

int Solve1(int y){
	if (y==0) return 0;
	if (y==1) {
		int cur=Press(1);
		if (cur==INF) return 3;
		return cur;
	}
	if (dp[y]!=-1) return dp[y];
	int res=Press(y);
	for (int i=2;i<y;i++) {
		if (y%i==0) {
			int l=Press(i);
			if (l!=INF) {
				int r=Solve1(y/i);
				if (r!=INF)	res=min(res,l+1+r);
			}
		}
	}
	dp[y]=res;
	return res;
}

int Solve(){
	if (n==0) return -1;
	int res=Solve1(x);
	if (res==INF) return -1;
	return res+1;
}

int main (){
	INF=numeric_limits<int>::max();
	fin>>T;
	for (int i=0;i<T;i++){
		s.clear();
		for (int j=0;j<10;j++){
			bool cur;
			fin>>cur;
			if (cur) {
				s.insert(j);
			}
		}
		fin>>x;
		n=s.size();
		memset(dp,-1,sizeof(dp));
		//if (i!=2) continue;
		int ret=Solve();
		if (ret!=-1){
			fout<<"Case #"<<i+1<<": "<<ret<<endl;
		}
		else {
			fout<<"Case #"<<i+1<<": "<<"Impossible"<<endl;
		}
		
	}
	return 0;
}
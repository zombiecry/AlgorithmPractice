#include <vector>
#include <set>
#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("B-large-practice.in");
ofstream fout("b.out");
#define cout fout
int INF;
int T;
int N,M;
struct Metro{
	int sn;
	int w;
	vector <int> t;
};
vector <Metro> A;
struct Tunnel{
	int m1,s1,m2,s2,t;
};
vector <Tunnel> ts;
int src,dst;
int Q;
vector<vector<int>> d;
int qx1,qy1,qx2,qy2;

typedef pair<int,int> scpair;
typedef pair<int,scpair> scpair1;

int Dist(int x,int cy1,int cy2){
	int waitt=A[x].w;
	int l=min(cy1,cy2);
	int r=max(cy1,cy2);
	int sum=0;
	for (int i=l;i<r;i++){
		sum+=A[x].t[i];
	}
	return waitt+sum;
}


int Solve(){
	int srcx=qx1-1,srcy=qy1-1;
	d[srcx][srcy]=0;
	set <scpair1> st;
	st.insert(scpair1(0,scpair(srcx,srcy)));
	while(!st.empty()){
		scpair1 t=*st.begin();
		st.erase(st.begin());
		int cx=t.second.first;
		int cy=t.second.second;
		int cd=t.first;
		for (int i=0;i<A[cx].sn;i++){
			if (i==cy) continue;
			int newd=cd+Dist(cx,cy,i);
			if (d[cx][i] > newd){
				st.erase(scpair1(d[cx][i],scpair(cx,i)));
				st.insert(scpair1(newd,scpair(cx,i)));
				d[cx][i]=newd;
			}
		}
		for (int i=0;i<ts.size();i++){
			Tunnel &ct=ts[i];
			if (ct.m1-1==cx && ct.s1-1==cy) {
				int vx=ct.m2-1;
				int vy=ct.s2-1;
				int newd=cd+ct.t;
				if (d[vx][vy] >newd){
					st.erase(scpair1(d[vx][vy],scpair(vx,vy)));
					st.insert(scpair1(newd,scpair(vx,vy)));
					d[vx][vy]=newd;
				}
				continue;
			}
			if (ct.m2-1==cx && ct.s2-1==cy) {
				int vx=ct.m1-1;
				int vy=ct.s1-1;
				int newd=cd+ct.t;
				if (d[vx][vy] >newd){
					st.erase(scpair1(d[vx][vy],scpair(vx,vy)));
					st.insert(scpair1(newd,scpair(vx,vy)));
					d[vx][vy]=newd;
				}
				continue;
			}
		}
	}
	if (d[qx2-1][qy2-1]==INF) return -1;
	return d[qx2-1][qy2-1];
}

int main (){
	INF=numeric_limits<int>::max();
	fin>>T;
	for (int i=0;i<T;i++){
		fin>>N;
		A.resize(N);
		d.resize(N);
		for (int j=0;j<N;j++){
			fin>>A[j].sn>>A[j].w;
			A[j].t.resize(A[j].sn-1);
			for (int k=0;k<A[j].sn-1;k++) {
				fin>>A[j].t[k];
			}
			d[j].resize(A[j].sn);
		}
		fin>>M;
		ts.resize(M);
		for (int j=0;j<M;j++){
			fin>>ts[j].m1>>ts[j].s1>>ts[j].m2>>ts[j].s2>>ts[j].t;
		}
		fin>>Q;
		cout<<"Case #"<<i+1<<":"<<endl;
		for (int j=0;j<Q;j++){
			fin>>qx1>>qy1>>qx2>>qy2;
			for (int i1=0;i1<N;i1++){
				fill(d[i1].begin(),d[i1].end(),INF);
			}
			cout<<Solve()<<endl;
		}
	}
	return 0;
}
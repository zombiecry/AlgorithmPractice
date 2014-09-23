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
using namespace std;
ifstream fin("C-large-practice.in");
ofstream fout("c.out");
int T;
int N;
int K;
vector <int> A;
vector <vector <int>>B;
vector <vector <int>>C;
int dp[101][101];
int Solve(int p,int q){
	if (dp[p][q]!=-1){return dp[p][q];}
	if (q-p+1<3){return q-p+1;}
	//[p,q] >=3
	int a=A[p];
	int res=numeric_limits<int>::max();
	for (int i=0;i<B[p].size();i++) for (int j=0;j<C[p].size();j++){
		int p1=B[p][i];
		int p2=C[p][j];
		if (p1>=p2){continue;}
		int f1=Solve(p+1,p1-1);
		if (f1!=0){continue;}
		int f2=Solve(p1+1,p2-1);
		if (f2!=0){continue;}
		if (p2<=q){
			res=min(res,Solve(p2+1,q));
		}
	}
	res=min(res,Solve(p+1,q)+1);
	dp[p][q]=res;
	return res;
}


int main (){
	fin>>T;
	for (int i=0;i<T;i++){
		if (i!=2-1){
			//continue;
		}
		fin>>N>>K;
		A.resize(0);
		B.resize(0);
		C.resize(0);
		A.resize(N);
		for (int j=0;j<N;j++){
			fin>>A[j];
		}
		B.resize(N);
		C.resize(N);
		for (int j=0;j<N;j++) for (int k=j+1;k<N;k++){
			if (A[k]-A[j]==K){
				B[j].push_back(k);
			}
			if (A[k]-A[j]==2*K){
				C[j].push_back(k);
			}
		}
		memset(dp,-1,sizeof(dp));
		fout<<"Case #"<<i+1<<": "<<Solve(0,N-1)<<endl;
	}
	return 0;
}
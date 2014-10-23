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
ifstream fin("A-large.in");
ofstream fout("al0.out");
int T;
int m,n;
long long dp[101][101];
const long long MODULAR=1000000007LL;
long long Solve(int p,int q){
	if (dp[p][q]!=-1){return dp[p][q];}
	if (p==0){
		if (q==0){return 1;}
		return 0;
	}
	long long res=0;
	if (p<q){
		res=0;
	}
	else{
		res+=Solve(p-1,q-1)*q;		//get from [0,q-1]
		res%=MODULAR;
		res+=Solve(p-1,q)*(m-q);
		res%=MODULAR;	
	}
	dp[p][q]=res;
	return res;
}


int main (){
	fin>>T;
	for (int i=0;i<T;i++){
		fin>>m>>n;
		memset(dp,-1,sizeof(dp));
		fout<<"Case #"<<i+1<<": "<<Solve(n,m)<<endl;
	}

	return 0;
}
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
ifstream fin("c.in");
ofstream fout("c.out");
#define cin fin
//#define cout fout
#endif
int dp[2102][2102];
string s1,s2;
int n,m;
int main(){
	memset(dp,0,sizeof(dp));
	cin>>s1>>s2;
	n=s1.length();
	m=s2.length();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) {
		dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		int l=0;
		for(;i-l-1>=0 && j-l-1>=0;l++){
			if (s1[i-1-l]!=s2[j-1-l]) break;
		}
		if(l<3) continue;
		dp[i][j]=max(dp[i][j],l+dp[i-l][j-l]);
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
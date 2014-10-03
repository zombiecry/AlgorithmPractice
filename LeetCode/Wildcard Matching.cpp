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
const int MAX_L=100000;
class Solution {
public:
	int m,n;
	int	   dp[2][MAX_L+1];
	bool isMatch(const char *s, const char *p) {
		memset(dp,-1,sizeof(dp));
		n=strlen(s);
		m=strlen(p);
		dp[0][0]=1;
		for (int i=1;i<=m;i++){
			dp[0][i]=0;
		}
		for (int i=1;i<=n;i++) {
			int cur=i%2;
			int prev=(i-1)%2;
			for (int j=1;j<=m;j++){
				switch(p[j-1]){
				case '?':
					dp[cur][j]=dp[prev][j-1];
					break;
				case '*':
					dp[cur][j]=dp[prev][j] | dp[cur][j-1] | dp[prev][j-1];
					break;
				default:
					dp[cur][j]=dp[prev][j-1];
					break;
				}
			}
		}
		return dp[n%2][m];
	}
};

int main (){
	Solution *sol=new Solution;
	const char *a="";
	const char *b="";
	cout<<sol->isMatch(a,b);
	return 0;
}
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
#define MAX_N 1<<15
int M,X;
double P;
int n;
int main(){
	M=3;
	P=0.75;
	X=60000;
	n=1<<M;
	vector<vector<double> >dp(2,vector<double>(n+1,0));
	//the highest level should be >= 10k,in which case it is 1.
	dp[1][n]=1;
	for(int t=M-1;t>=0;t--) {	//for every previous turn
		int cur=t%2;
		int prev=(t+1)%2;
		for(int j=0;j<=n;j++) {
			dp[cur][j]=0;
			double cp=0;
			for(int k=0;k<=j;k++){
				cp=max(cp,dp[prev][min(j+k,n)]*P+dp[prev][j-k]*(1-P));
			}
			dp[cur][j]=cp;
		}
	}
	int deg=(double(X)/100000.0)*n;
	cout<<dp[0][deg]<<endl;
	return 0;
}
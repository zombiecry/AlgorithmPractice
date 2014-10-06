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
const int MAX_N=2000;
class Solution {
public:
	int n,m;
	vector<vector<bool>> dp;
	vector <string>      dps[5][MAX_N+1];
	int GetInt(string &s){
		stringstream ss;
		ss.str(s);
		int res;
		ss>>res;
		return res;
	}
	vector<string> restoreIpAddresses(string s) {
		n=s.length();
		dp.resize(5,vector<bool>(n+1,false));
		dp[0][0]=true;
		for (int i=1;i<=4;i++){
			for (int j=1;j<=n;j++){
				dp[i][j]=false;
				for (int k=j-3;k<j;k++){
					if (k<0){continue;}
					string curs=s.substr(k,j-k);
					if (curs.length()>1){
						if (curs[0]=='0'){continue;}
					}
					int cur=GetInt(curs);
					if (cur>255){continue;}
					dp[i][j] =dp[i][j] || dp[i-1][k];
				}
			}
		}
		dps[0][0].push_back("");
		for (int i=1;i<=4;i++){
			for (int j=1;j<=n;j++){
				if (!dp[i][j]){continue;}
				vector<string> &dst=dps[i][j];
				for (int k=j-3;k<j;k++){
					if (k<0){continue;}
					if (!dp[i-1][k]){continue;}
					string curs=s.substr(k,j-k);
					if (curs.length()>1){
						if (curs[0]=='0'){continue;}
					}
					int cur=GetInt(curs);
					if (cur>255){continue;}
					vector<string> &pres=dps[i-1][k];
					for (int ii=0;ii<pres.size();ii++){
						string temp=pres[ii];
						if (pres[ii].length()>0){
							temp+=".";
						}
						temp+=curs;
						dst.push_back(temp);
					}
				}
			}
		}
		return dps[4][n];
	}
};

int main (){
	string s="010010";
	Solution *sol=new Solution;
	vector <string> ret=sol->restoreIpAddresses(s);
	for (int i=0;i<ret.size();i++){
		cout<<ret[i]<<endl;
	}
	system("pause");
	return 0;
}
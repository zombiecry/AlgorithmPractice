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
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		int n=strlen(s);
		int m=strlen(p);
		vector <vector<int>> dp(n+1,vector<int>(m+1,0));
		dp[0][0]=true;
		bool empty=true;
		for (int i=0;i<m-1;i++){
			char cp=*(p+i);
			char cp1=*(p+i+1);
			if (cp1!='*'){break;}
			else{
				i++;
			}
			dp[0][i+1]=true;
		}
		for (int i=1;i<=n;i++){
			char cs=*(s+i-1);
			for (int j=1;j<=m;j++){
				char cp=*(p+j-1);
				char cp1=*(p+j);
				if (cp1=='*'){continue;}
				if (cp=='*'){
					char cpp=*(p+j-2);
					dp[i][j] |= dp[i][j-2];
					if (cpp==cs || cpp=='.'){
						dp[i][j]|=dp[i-1][j];
					}
				}
				else if (cp=='.'){
					dp[i][j]|=dp[i-1][j-1];
				}
				else {
					if (cp==cs){
						dp[i][j]|=dp[i-1][j-1];
					}
				}

			}
		}
		return dp[n][m];
	}
};

int main (){
	Solution *sol=new Solution;
	cout<<sol->isMatch("aaaaaaaaaaaaab","a*a*a*a*a*a*a*a*a*a*c");
	system("pause");
	return 0;
}
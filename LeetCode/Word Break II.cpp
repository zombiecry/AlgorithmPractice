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
#include <unordered_set>
using namespace std;
const int MAX_N=1000;
class Solution {
public:
	int m,n;
	vector <vector<int>>	dp[MAX_N];
	bool					dpf[MAX_N];
	void ConCat(vector<vector<int>> &res,vector <vector<int>> &prevs,int cur){
		for (int i=0;i<prevs.size();i++){
			vector<int> temp=prevs[i];
			temp.push_back(cur);
			res.push_back(temp);
		}
	}
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		memset(dpf,0,sizeof(dpf));
		n=s.length();
		dpf[0]=true;
		for(int i=1;i<=n;i++){
			for (int j=0;j<i;j++){
				string cur=s.substr(j,i-j);
				if (dict.find(cur)!=dict.end()){
					dpf[i]|=dpf[j];
				}
			}
		}
		vector <string> res;
		if (!dpf[n]){
			return res;
		}
		dp[0].push_back(vector<int>(1,0));
		for(int i=1;i<=n;i++){
			if (!dpf[i]){continue;}
			for (int j=0;j<i;j++){
				if (!dpf[j]){continue;}
				string cur=s.substr(j,i-j);
				if (dict.find(cur)!=dict.end()){
					ConCat(dp[i],dp[j],i);
				}

			}
		}
		res.resize(dp[n].size(),"");
		for (int i=0;i<dp[n].size();i++){
			for (int j=0;j<dp[n][i].size()-1;j++){
				string temp=s.substr(dp[n][i][j],dp[n][i][j+1]-dp[n][i][j]);
				if (j>0){res[i]+=" ";}
				res[i]+=temp;
			}
		}
		return res;
	}
};

int main (){
	Solution *sol=new Solution;
	string s="catsanddog";
	string dd[]={"cat", "cats", "and", "sand", "dog"};
	//string s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
	//string dd[]={"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
	unordered_set <string> dict;
	dict.insert(dd,dd+5);
	vector<string> res= sol->wordBreak(s,dict);
	for (int i=0;i<res.size();i++){
		cout<<res[i]<<endl;
	}
	return 0;
}
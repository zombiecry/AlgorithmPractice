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
#include <unordered_map>
using namespace std;
class Solution {
public:
	int n,m,ln;
	unordered_map <string,int> lm;
	vector<int> findSubstring(string S, vector<string> &L) {
		n=S.length();
		m=L.size();
		ln=L[0].size();
		vector <int> res;
		for (int i=0;i<m;i++) {
			string temp=L[i];
			if (lm.find(temp)==lm.end()) lm[temp]=1;
			else lm[temp]++;
		}
		unordered_map <string,int> orglm=lm;
		for (int i=0;i+ln*m<=n;i++){
			bool okflag=true;
			lm=orglm;
			for (int j=0;j<m;j++) {
				string cur=S.substr(i+j*ln,ln);
				if (lm.find(cur)==lm.end()) {okflag=false;break;}
				if (--lm[cur]<0){okflag=false;break;}
			}
			if (okflag) res.push_back(i);
		}
		return res;
	}
};
int main (){
	Solution *sol=new Solution;
	string S="a";
	string la[]={"a"};
	vector<int> ret=sol->findSubstring(S,vector<string>(la,la+sizeof(la)/sizeof(la[0])));
	for (int i=0;i<ret.size();i++) cout<<ret[i]<<" ";
	cout<<endl;
	system("pause");
	return 0;
}
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
	vector <string>			   L;
	unordered_map<string,int>  cm;
	string S;
	bool Check(int p,vector<string> &L){
		vector <int> fvec(cm.size(),0);
		for (int i=0;i<m;i++){
			int realIndex=cm[L[i]];
			fvec[realIndex]++;
		}
		for (int i=0;i<m;i++){
			int pos=p+i*ln;
			string cur=S.substr(pos,ln);
			if (cm.find(cur)==cm.end()){return false;}
			int curIndex=cm[cur];
			fvec[curIndex]--;
			if (fvec[curIndex]<0){return false;}
		}
		return true;
	}
	vector<int> findSubstring(string S, vector<string> &L) {
		n=S.length();
		m=L.size();
		ln=L[0].length();
		this->S=S;
		for (int i=0;i<m;i++){
			if (cm.find(L[i])==cm.end()){cm[L[i]]=i;}
		}
		vector <int> res;
		for (int i=0;i+ln*m<=n;i++){
			if (Check(i,L)){
				res.push_back(i);
			}
		}
		return res;
	}
};
int main (){
	Solution *sol=new Solution;
	string S="lingmindraboofooowingdingbarrwingmonkeypoundcake";
	string la[]={"fooo","barr","wing","ding","wing"};
	sol->findSubstring(S,vector<string>(la,la+sizeof(la)/sizeof(la[0])));
	return 0;
}
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

typedef pair<int,int> scpair;
class Solution {
public:
	int m,n;
	void reverseWords(string &s) {
		vector <scpair> pvec;
		n=s.length();
		bool conti=false;
		for (int i=0;i<n;i++){
			if (s[i]!=' '){
				if (!conti){
					pvec.push_back(scpair(i,n-i));
					conti=true;
				}
			}
			else{
				if (conti){
					conti=false;
					int cur=pvec.size()-1;
					pvec[cur].second=i-pvec[cur].first;
				}
			}
		}
		m=pvec.size();
		string res;
		for (int i=m-1;i>=0;i--){
			string cur=s.substr(pvec[i].first,pvec[i].second);
			res+=cur;
			if (i>0){
				res+=" ";
			}
		}
		s=res;
	}
};
int main(){
	Solution *sol=new Solution;
	string  s = "the sky is blue";
	sol->reverseWords(s);
	cout<<s<<endl;
	return 0;
}
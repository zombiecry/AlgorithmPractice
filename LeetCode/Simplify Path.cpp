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
	int n,m;
	string path;
	int Next(int p,string &s){
		while (p<path.length()){
			if (path[p]=='/'){
				p++;
			}
			else{break;}
		}
		if (p==path.length()){return p;}
		size_t q=path.find('/',p);
		if (q==string::npos){
			s=path.substr(p,path.length()-p);
			return path.length();
		}
		s=path.substr(p,q-p);
		return q;
	}
	string simplifyPath(string path) {
		n=path.length();
		this->path=path;
		int p=0;
		vector <string> st;
		while (p<n){
			string s;
			p=Next(p,s);
			if (s.length()==0){continue;}
			if (s=="."){continue;}
			if (s==".."){
				if (!st.empty()){st.pop_back();}
				continue;
			}
			st.push_back(s);
		}
		string res="/";
		for (int i=0;i<st.size();i++){
			res+=st[i];
			if (i<st.size()-1){
				res+="/";
			}
		}
		return res;
	}
};

int main (){
	Solution *sol=new Solution;
	cout<<sol->simplifyPath("/.");

}
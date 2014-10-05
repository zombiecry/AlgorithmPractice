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
	int GetNum(string &s){
		stringstream ss;
		ss.str(s);
		int res;
		ss>>res;
		return res;
	}
	int Op(int a,int b,char op){
		switch(op){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		}
		return -1;
	}
	bool isOp(string &s){
		return s=="+" || s=="-" || s=="*" || s=="/";
	}
	int evalRPN(vector<string> &tokens) {
		n=tokens.size();
		vector <string> &t=tokens;
		if (n==0){return 0;}
		stack <int> st;
		for (int i=0;i<n;i++){
			string cur=t[i];
			if (isOp(cur)){
				int b=st.top();
				st.pop();
				int a=st.top();
				st.pop();
				a=Op(a,b,cur[0]);
				st.push(a);
			}
			else{
				st.push(GetNum(cur));
			}
		}
		return st.top();
	}
};
int main(){
	Solution *sol=new Solution;
	string s[]={"0","3","/"};
	cout<<sol->evalRPN(vector<string>(s,s+3));
	return 0;
}
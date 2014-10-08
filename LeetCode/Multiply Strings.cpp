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
	string Mul(char ch,string &s){
		int up=0;
		int ich=ch-'0';
		string res;
		for (int i=0;i<n;i++){
			int ia=s[i]-'0';
			int cur=ia*ich + up;
			up=cur/10;
			cur=cur%10;
			res.push_back('0'+cur);
		}
		if (up) res.push_back('0'+up);
		return res;
	}
	string Add(string &c,string &r,int p){
		string res;
		int up=0;
		for (int i=0;i<max(c.length(),r.length()+p);i++){
			char a,b;
			if (i>=c.length()) a='0';
			else a=c[i];
			if (i<p || i>=(r.length()+p)) b='0';
			else b=r[i-p];
			int ia=a-'0';
			int ib=b-'0';
			int cc=ia+ib+up;
			up=cc/10;
			cc=cc%10;
			res.push_back('0'+cc);
		}
		if (up) res.push_back('0'+up);
		return res;
	}
	string multiply(string num1, string num2) {
		reverse(num1.begin(),num1.end());
		reverse(num2.begin(),num2.end());
		n=num1.length();
		m=num2.length();
		string cur;
		for (int i=0;i<m;i++){
			char ch=num2[i];
			string r=Mul(ch,num1);
			cur=Add(cur,r,i);
		}
		reverse(cur.begin(),cur.end());
		bool conflag=true;
		int preZero=0;
		for (int i=0;i<cur.length()-1;i++){
			if (cur[i]!='0'){
				conflag=false;
			}
			else{
				if (conflag){
					preZero++;
				}
			}
		}

		return cur.substr(preZero,cur.length()-preZero);
	}
};

int main(){
	string s1="408";
	string s2="0";
	Solution *sol=new Solution;
	cout<<sol->multiply(s1,s2)<<endl;
	system("pause");
	return 0;
}
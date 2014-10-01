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

ifstream fin("a.in");
int trans[10][6]={
	{ 0, 1, 2, 9,-1,-1},
	{-1,-1, 2, 9,-1,-1},
	{ 8,-1, 2, 3, 5,-1},
	{ 8,-1, 4,-1, 5,-1},	//.
	{ 8,-1, 4,-1, 5,-1},					//\d+
	{-1, 6, 7,-1,-1,-1},//e
	{-1,-1, 7,-1,-1,-1},//-
	{ 8,-1, 7,-1,-1,-1},//\d+
	{ 8,-1,-1,-1,-1,-1},//$
	{-1,-1, 4,-1,-1,-1}	//.
};
class Solution {
public:
	int m,n;
	string s;
	int GetItem(char a){
		if (a==' '){return 0;}
		if (a=='-' || a=='+'){return 1;}
		if (a>='0' && a<='9'){return 2;}
		if (a=='.'){return 3;}
		if (a=='e'){return 4;}
		return 5;
	}
	bool Solve(int p,int stat){
		if (p==n){
			if (stat==2 || stat==3 || stat==4|| stat==7|| stat==8){return true;}
			return false;
		}
		int curT=GetItem(s[p]);
		int ns=trans[stat][curT];
		if (ns==-1){return false;}
		return Solve(p+1,ns);
	}

	bool isNumber(const char *s) {
		this->s=string(s);
		n=this->s.length();
		return Solve(0,0);
	}
};

int main (){
	Solution *sol=new Solution;
	cout<<sol->isNumber("+.8")<<endl;
	system("pause");
	return 0;
}
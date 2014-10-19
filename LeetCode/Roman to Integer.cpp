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
	int romanToInt(string s) {
		string rt[][9]={
			{"I","II","III","IV","V","VI","VII","VIII","IX"},
			{"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
			{"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
			{"M","MM","MMM","CD","D","DC","DCC","DCCC","CM"},
		}; 
		int res=0;
		int r=s.length();
		int bi=1;
		int count=0;
		while(r){
			int pos=r;
			int len=0;
			int di=0;
			for (int i=8;i>=0;i--){
				string cd=rt[count][i];
				int cl=cd.length();
				if (r-cl<0) continue;
				if (s.substr(r-cl,cl)==cd) {
					if (cl>len) {
						len=cl;
						pos=r-cl;
						di=i+1;
					}
				}
			}
			res+=di*bi;
			r=pos;
			count++;
			bi*=10;
		}
		return res;
	}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->romanToInt("MDCCCLXXXIV");
	system("pause");
	return 0;
}
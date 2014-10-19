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
	string convert(string s, int nRows) {
		n=nRows;
		if(n==1) return s;
		m=s.length();
		vector<string> vs(n);
		int c=-1;
		for(int i=0;i<m;i++) {
			int x=i%(2*n-2);
			int r;
			if(x<n) {
				if (x==0)  {c++;for(int i=0;i<n;i++) vs[i]+=' ';}
				r=x;
			}
			else {
				r=n-1-(x-n+1);
				c++;
				for(int i=0;i<n;i++) vs[i]+=' ';
			}
			vs[r][c]=s[i];
		}
		string res;
		for(int i=0;i<n;i++) {
			string cur;
			for(int j=0;j<vs[i].length();j++){
				if(vs[i][j]!=' ') {
					cur+=vs[i][j];
				}
			}
			res+=cur;
		}
		return res;
	}
};

int main(){
	Solution *sol=new Solution;
	cout<<sol->convert("PAYPALISHIRING",3)<<endl;
	system("pause");
	return 0;
}
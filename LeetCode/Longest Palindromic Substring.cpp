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
	string longestPalindrome(string s) {
		n=s.length();
		string ss;
		for(int i=0;i<n;i++){
			ss+="#";
			ss+=s[i];
		}
		ss+="#";
		m=ss.length();
		vector <int> p(m,0);
		int mx=0;
		int id=0;
		for(int i=1;i<m;i++){
			if (mx>i) p[i]=min(p[2*id-i],mx-i);
			for(int j=p[i]+1;i+j<m && i-j>=0;j++){
				if (ss[i-j]==ss[i+j]) p[i]++;
				else break;
			}
			if (i+p[i]>mx){
				id=i;
				mx=i+p[i];
			}
		}
		int maxp=0;
		for (int i=0;i<m;i++) {
			if(p[i]>maxp) {
				id=i;
				maxp=p[i];
			}
		}
		string res;
		for(int i=id-maxp;i<=id+maxp;i++){
			if(ss[i]!='#') res+=ss[i];
		}
		return res;
	}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->longestPalindrome("ccd")<<endl;;
	system("pause");
	return 0;
}
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
	bool Check(char ch){
		if (ch>='0' && ch<='9') return true;
		if (ch>='a' && ch<='z') return true;
		if (ch>='A' && ch<='Z') return true;
		return false;
	}
	bool Equal(char ch1,char ch2){
		if (ch1==ch2) return true;
		if (ch1>='A' && ch1<='Z') ch1=ch1-'A'+'a';
		if (ch2>='A' && ch2<='Z') ch2=ch2-'A'+'a';
		return ch1==ch2;
	}
	bool isPalindrome(string s) {
		n=s.length();
		int l=0;
		int r=n-1;
		while(l<r){
			while(!Check(s[l]) && l<r) l++;
			while(!Check(s[r]) && l<r) r--;
			if (l>=r) break;
			if (!Equal(s[l],s[r])) return false;
			l++;
			r--;
		}
		return true;
	}
};
int main(){
	Solution *sol=new Solution;
	cout<<sol->isPalindrome("aA");
	system("pause");
	return 0;
}
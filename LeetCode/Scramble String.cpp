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
	bool isScramble(string s1, string s2) {
		int n,m;
		n=s1.length();
		m=s2.length();
		if (n!=m) return false;
		if (n==1) return s1[0]==s2[0];
		for (int i=1;i<n;i++){
			string l1=s1.substr(0,i);
			string r1=s1.substr(i,n-i);

			string l2=s2.substr(0,i);
			string r2=s2.substr(i,n-i);

			string l3=s2.substr(n-i,i);
			string r3=s2.substr(0,n-i);
			if (isScramble(l1,l2) && isScramble(r1,r2)) return true;
			if (isScramble(l1,l3) && isScramble(r1,r3)) return true;
		}
		return false;
	}
};

int main (){
	Solution *sol=new Solution;
	cout<<sol->isScramble("abb","bab");
	return 0;
}
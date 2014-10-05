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
	int longestValidParentheses(string s) {
		n=s.length();
		int res=0;
		int count=0;
		int par=0;
		for (int i=0;i<n;i++){
			if (s[i]=='('){
				count++;
				continue;
			}
			if (s[i]==')'){
				count--;
				if (count==0){
					par++;
				}
				if (count<0){
					count=0;
					res=max(res,par);
					par=0;
				}
			}
		}
		res=max(res,par);
		return res*2;
	}
};

int main (){
	return 0;
}
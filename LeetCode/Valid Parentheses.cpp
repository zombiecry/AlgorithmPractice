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
	int n;
	bool isValid(string s) {
		stack<char> st;
		n=s.length();
		for (int i=0;i<n;i++){
			char ch=s[i];
			if (ch==')'){
				if (st.empty()) return false;
				if (st.top()!='(') return false;
			}
			else if (ch==']'){
				if (st.empty()) return false;
				if (st.top()!='[') return false;
			}
			else if (ch=='}'){
				if (st.empty()) return false;
				if (st.top()!='{') return false;
			} 
			else {
				st.push(ch);
				continue;
			}
			st.pop();
		}
		if (st.empty()) return true;
		return false;
	}
};

int main (){
	Solution *sol=new Solution;
	cout<<sol->isValid("()");
	system("pause");
	return 0;
}
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
	int largestRectangleArea(vector<int> &height) {
		n=height.size();
		if (n==0) return 0;
		stack<int> st;
		st.push(height[0]);
		int cur=height[0];
		int res=cur;
		for (int i=1;i<n;i++){
			if (height[i]>=cur){
				st.push(height[i]);
			}
			else{
				int count=0;
				while (!st.empty()){
					if (st.top()<height[i]){
						break;
					}
					st.pop();
					count++;
				}
				res=max(res,count*cur);
				cur=height[i];
				st.push(height[i]);
			}
		}
		int count=0;
		while(!st.empty()){
			count++;
			st.pop();
		}
		res=max(res,count*cur);
		return res;
	}
};

int main (){
	Solution *sol=new Solution;
	int a[]={}
	vector<int> hs;
	sol->largestRectangleArea()
	return 0;
}
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

typedef pair<int,pair<int,int>> scpair;
class Solution {
public:
	int m,n;
	vector<vector<int> > threeSum(vector<int> &num) {
		n=num.size();
		vector<vector<int> > res;
		if (n<3) return res;
		vector<int> &a=num;
		set   <scpair> st;
		sort(a.begin(),a.end());
		for (int i=0;i<n-2;i++) {
			scpair cr;
			cr.first=a[i];
			int l=i+1;
			int r=n-1;
			int x=0-a[i];
			while(l<r){
				int cs=a[l]+a[r];
				if (cs<x) l++;
				else if(cs>x) r--;
				else {
					cr.second.first =a[l];
					cr.second.second=a[r];
					st.insert(cr);
					l++;
				}
			}
		}
		for (auto it=st.begin();it!=st.end();it++) {
			vector<int> cur(3,0);
			cur[0]=it->first;
			cur[1]=it->second.first;
			cur[2]=it->second.second;
			res.push_back(cur);
		}
		return res;
	}
};

int main (){
	Solution *sol=new Solution;
	int a[]={7,5,-8,-6,-13,7,10,1,1,-4,-14,0,-1,-10,1,-13,-4,6,-11,8,-6,0,0,-5,0,11,-9,8,2,-6,4,-14,6,4,-5,0,-12,12,-13,5,-6,10,-10,0,7,-2,-5,-12,12,-9,12,-9,6,-11,1,14,8,-1,7,-13,8,-11,-11,0,0,-1,-15,3,-11,9,-7,-10,4,-2,5,-4,12,7,-8,9,14,-11,7,5,-15,-15,-4,0,0,-11,3,-15,-15,7,0,0,13,-7,-12,9,9,-3,14,-1,2,5,2,-9,-3,1,7,-12,-3,-1,1,-2,0,12,5,7,8,-7,7,8,7,-15};
	vector<vector<int> > ret=sol->threeSum(vector<int>(a,a+sizeof(a)/sizeof(a[0])));
	for (int i=0;i<ret.size();i++){
		cout<<ret[i][0]<<" "<<ret[i][1]<<" "<<ret[i][2]<<endl;
	}
	system("pause");
	return 0;
}
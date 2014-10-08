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
typedef pair<int,int> scpair;
class Solution {
public:
	int m,n;
	vector<vector<int> > threeSum(vector<int> &num) {
		n=num.size();
		vector<vector<int> > res;
		if (n<3){return res;} 
		vector <scpair> b;
		b.resize(n);
		for (int i=0;i<n;i++){
			b[i].first=num[i];
			b[i].second=i;
		}
		sort(b.begin(),b.end());
		int count=0;
		set<vector<int>> st;
		for (int i=0;i<n-2;i++) for (int j=i+1;j<n-1;j++) {
			int left=0-b[i].first-b[j].first;
			if (left<b[j].first){continue;};
			vector<scpair>::iterator p=std::lower_bound(b.begin()+j+1,b.end(),scpair(left,0));
			if (p==b.end()){continue;}
			else{
				if (p->first!=left){continue;}
				vector <int> cur;
				cur.push_back(b[i].first);
				cur.push_back(b[j].first);
				cur.push_back(p->first);
				st.insert(cur);
			}
		}
		for (set<vector<int>>::iterator it=st.begin();it!=st.end();it++){
			res.push_back(*it);
		}
		return res;
	}
};

int main (){
	Solution *sol=new Solution;
	int a[]={7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
	vector <int> v(a,a+sizeof(a)/sizeof(a[0]));
	vector<vector<int>>ret=sol->threeSum(v);
	for (int i=0;i<ret.size();i++){
		for (int j=0;j<ret[i].size();j++){
			cout<<ret[i][j]<<" ";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
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
	int n;
	vector <scpair> a;
	vector<int> twoSum(vector<int> &numbers, int target) {
		n=numbers.size();
		a.resize(n);
		for (int i=0;i<n;i++){
			a[i]=scpair(numbers[i],i+1);
		}
		sort(a.begin(),a.end());
		vector <int> res;
		for (int i=0;i<n-1;i++){
			int left=target-a[i].first;
			int p=lower_bound(a.begin()+i+1,a.end(),scpair(left,0))-a.begin();
			if (p<n){
				if (a[p].first!=left){continue;}
				res.push_back(a[i].second);
				res.push_back(a[p].second);
				sort(res.begin(),res.end());
				return res;
			}
		}
		return res;
	}
};

int main (){
	Solution *sol=new Solution;
	int a[]={150,24,79,50,88,345,3};
	int t=200;
	vector<int> ret=sol->twoSum(vector<int>(a,a+sizeof(a)/sizeof(a[0])),t);
	for (int i=0;i<ret.size();i++){
		cout<<ret[i]<<" ";
	}
	return 0;
}
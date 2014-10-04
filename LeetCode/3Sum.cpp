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
	int m,n;
	vector<vector<int> > threeSum(vector<int> &num) {
		n=num.size();
		vector<vector<int> > res;
		if (n<3){return res;} 
		sort(num.begin(),num.end());
		for (int i=0;i<n-2;i++) for (int j=i+1;j<n-1;j++) for (int k=j+1;k<n;k++){
			if (num[i]+num[j]+num[k]==0){
				vector <int> a(3,0);
				a[0]=num[i];
				a[1]=num[j];
				a[2]=num[k];
				if (res.size()>0){
					bool same=true;
					for (int t=0;t<3;t++){
						if (a[t]!=res[res.size()-1][t]){
							same=false;
							break;
						}
					}
					if (same){continue;}
				}
				res.push_back(a);
			}
		}
		return res;
	}
};

int main (){
	Solution *sol=new Solution;
	int a[]={7,5,-8,-6,-13,7,10,1,1,-4,-14,0,-1,-10,1,-13,-4,6,-11,8,-6,0,0,-5,0,11,-9,8,2,-6,4,-14,6,4,-5,0,-12,12,-13,5,-6,10,-10,0,7,-2,-5,-12,12,-9,12,-9,6,-11,1,14,8,-1,7,-13,8,-11,-11,0,0,-1,-15,3,-11,9,-7,-10,4,-2,5,-4,12,7,-8,9,14,-11,7,5,-15,-15,-4,0,0,-11,3,-15,-15,7,0,0,13,-7,-12,9,9,-3,14,-1,2,5,2,-9,-3,1,7,-12,-3,-1,1,-2,0,12,5,7,8,-7,7,8,7,-15};
	sol->threeSum(vector<int>(a,a+sizeof(a)/sizeof(a[0])));
	return 0;
}
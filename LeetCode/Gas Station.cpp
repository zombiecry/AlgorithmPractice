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
#define ASIZE(x) \
	(sizeof(x)/sizeof(x[0]))
class Solution {
public:
	int n,m;
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		n=gas.size();
		vector<int> d=gas;
		for(int i=0;i<n;i++) d[i]-=cost[i];
		int l=-1;
		int maxs=-1;
		int cs=-1;
		int cl=-1;
		for(int i=0;i<2*n;i++) {
			int ci=i%n;
			if(cs<0) {cs=d[ci];cl=ci;}
			else cs+=d[ci];
			if(cs>maxs) {
				maxs=cs;
				l=cl;
			}
		}
		int cur=0;
		for (int i=0;i<n;i++) {
			int cp=(l+i)%n;
			cur+=d[cp];
			if(cur<0) return -1;
		}
		return l;
	}
};

int main(){
	int g[]={67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66};
	int c[]={27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
	Solution *sol=new Solution;
	cout<<sol->canCompleteCircuit(vector<int>(g,g+ASIZE(g)),vector<int>(c,c+ASIZE(c)))<<endl;
	system("pause");
	return 0;
}
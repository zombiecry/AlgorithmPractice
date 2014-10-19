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
	int searchInsert(int A[], int n, int target) {
		int l=0,r=n-1;
		while(l<r){
			int mid=(l+r)/2;
			if (A[mid]==target) {l=mid;break;}
			if (target<A[mid]) r=mid;
			else l=mid+1;
		}
		if (A[l]>=target) return l;
		return min(n,l+1);
	}
};

int main (){
	Solution *sol=new Solution;
	int a[]={1,3};
	cout<<sol->searchInsert(a,2,2);
	system("pause");
	return 0;
}
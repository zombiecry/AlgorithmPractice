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
	void merge(int A[], int m, int B[], int n) {
		//memcpy(A+n,A,m*sizeof(int));  //error in gcc, succeed in msvc because of filling order
		for(int i=m-1;i>=0;i--) A[i+n]=A[i];
		int p=n;
		int q=0;
		int r=0;
		while(p<n+m && q<n){
			if (A[p]>B[q]) {
				A[r]=B[q];
				r++;q++;
			}
			else {
				A[r]=A[p];
				r++;p++;
			}
		}
		while(p<n+m) A[r++]=A[p++];
		while(q<n) A[r++]=B[q++];
	}
};

int main (){
	Solution *sol=new Solution;
	int A[]={-10,-10,-10,-10,-9,-9,-9,-9,-9,-8,-8,-8,-8,-8,-7,-6,-6,-6,-6,-6,-6,-6,-5,-5,-5,-4,-4,-4,-4,-4,-4,-4,-4,-3,-3,-3,-2,-2,-1,-1,-1,0,0,0,0,0,1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,3,4,5,5,5,5,5,5,5,6,6,6,6,6,7,7,7,7,7,7,8,8,8,8,8,9,9,9,9,-10,-10,-10,-10,-10,-10,-9,-9,-9,-8,-8,-8,-8,-7,-7,-7,-7,-7,-7,-6,-6,-6,-6,-6,-6,-5,-5,-5,-5,-4,-4,-4,-3,-3,-3,-3,-2,-2,-2,-2,-2,-2,-1,-1,0,1,1,1,2,2,2,2,2,2,2,2,2,3,3,4,4,4,5,5,5,5,6,6,6,6,6,6,6,7,8,8,8,9,9,9,9,9};
	int B[]={-10,-10,-10,-10,-10,-10,-9,-9,-9,-8,-8,-8,-8,-7,-7,-7,-7,-7,-7,-6,-6,-6,-6,-6,-6,-5,-5,-5,-5,-4,-4,-4,-3,-3,-3,-3,-2,-2,-2,-2,-2,-2,-1,-1,0,1,1,1,2,2,2,2,2,2,2,2,2,3,3,4,4,4,5,5,5,5,6,6,6,6,6,6,6,7,8,8,8,9,9,9,9,9};
	int mn=sizeof(A)/sizeof(A[0]);
	int n=sizeof(B)/sizeof(B[0]);
	sol->merge(A,mn-n,B,n);
	for (int i=0;i<mn;i++) cout<<A[i]<<" ";
	system("pause");
	return 0;
}
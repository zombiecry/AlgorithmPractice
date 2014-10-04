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
	vector <int> A;
	int Solve(int p,int q){
		int l=p,r;
		int res=numeric_limits<int>::min();

		for (int i=p;i<q;i++){
			if (A[i]==0){
				res=max(res,0);
				res=max(res,Solve(l,i));
				l=i+1;
				continue;
			}
		}
		p=l;
		if (q-p<1){return res;}
		int count=0;
		int an=1;
		l=n;
		r=0;
		for (int i=p;i<q;i++){
			if (A[i]<0){
				count++;
				l=min(l,i);
				r=max(r,i);
			}
			an*=A[i];
		}
		res=max(res,an);
		if (count%2==0){return res;}
		res=max(res,A[l]);
		res=max(res,A[r]);
		if (r-p>=1){
			int ln=1;
			for (int i=p;i<r;i++){
				ln*=A[i];
			}
			res=max(res,ln);
		}
		if (q-l-1>=1){
			int rn=1;
			for (int i=l+1;i<q;i++){
				rn*=A[i];
			}
			res=max(res,rn);
		}
		return res;
	}

	int maxProduct(int A[], int n) {
		this->A=vector<int>(A,A+n);
		this->n=n;
		return Solve(0,n);
	}
};

int main (){
	Solution *sol=new Solution;
	int A[]={6,3,-10,0,2};
	cout<<sol->maxProduct(A,5)<<endl;
}
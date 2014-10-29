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
//the RMQ implement
const int MAX_N=1<<17;
int n,dat[2*MAX_N-1];
const int INF=9999;
//update the ith val to be x
void Update(int idx,int x){
	idx+=n;
	dat[idx]=x;
	while(idx>0){
		int father=idx/2;
		if (dat[father]<x) dat[father]=x;
		else break;
	}
}

int Query(int a,int b,int idx,int l,int r){
	if (r<a||l>b) return INF;
	if (l>=a && r<=b) return dat[idx];
	int vl=Query(a,b,idx*2,l,(l+r)/2);
	int vr=Query(a,b,idx*2+1,(l+r)/2,r);
	return min(vl,vr);
}
//the BIT inplement
int bit[MAX_N+1];
void Init(){
	memset(bit,0,sizeof(bit));
}
int Sum(int idx){
	int res=0;
	while(idx){
		res+=bit[idx];
		idx-=idx & (-idx);
	}
	return res;
}

void Add(int idx,int val){
	while(idx<n){
		bit[idx]+=val;
		idx+=idx &(-idx);
	}
}

int MergeCount(vector<int> &a){
	if (a.size()<=1) return 0;
	int n=a.size();
	vector<int> b(a.begin(),a.begin()+n/2);
	vector<int> c(a.begin()+n/2,a.end());
	int cnt1=MergeCount(b);
	int cnt2=MergeCount(c);
	int p=0,q=0,r=0;
	int res=cnt1+cnt2;
	while(p<b.size() || q<c.size()){
		if (p==b.size()){ a[r++]=c[q++];continue;}
		if (q==c.size()){ a[r++]=b[p++];continue;}
		if (b[p]>c[q]) {
			res+=n/2-p;
			a[r++]=c[q++];
			continue;
		}
		a[r++]=b[q++];
	}
	return res;
}

int main (){
	int a[]={3,1,4,2};
	n=4;

	int res=0;
	vector<int> av(a,a+n);
	res=MergeCount(av);
	cout<<res<<endl;
	return 0;
}
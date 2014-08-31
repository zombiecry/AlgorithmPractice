#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
string A,B;
int mem[1000][1000][2];
int Solve(int p,int q,int l){
	if (mem[p][q][l]!=-1){return mem[p][q][l];}
	if (p==A.size()){return 0;}
	if (q==B.size()){return 0;}
	int res=0;
	if (A[p]==B[q]){
		res=Solve(p+1,q+1,1)+1;
	}
	if (l==0){
		res=max(res,Solve(p,q+1,0));
		res=max(res,Solve(p+1,q,0));
	}
	mem[p][q][l]=res;
	return res;
}


int main (){
	memset(mem,-1,sizeof(mem));
	cin>>A;
	cin>>B;
	n=B.size();
	cout<<Solve(0,0,0)<<endl;
	return 0;
}

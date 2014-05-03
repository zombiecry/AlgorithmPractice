#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;
#if 0
ifstream fin("string.in");
ofstream fout("string.out");
#define cin fin
#define cout fout
#endif

int cn;
string invStr="Impossible";
unsigned long c[34][34];

bool Fill(int m,int n,unsigned long k,int *a){
	if (k>c[m][n]){
		return false;
	}

	if (m==0 && n==0){
		return true;
	}
	if (m==0){
		for (int i=n-1;i>=0;i--){
			a[i]=0;
		}
		return true;
	}
	if (n==0){
		for (int i=m-1;i>=0;i--){
			a[i]=1;
		}
		return true;
	}


	if (k<=c[m][n-1]){
		a[0]=0;
		return Fill(m,n-1,k,a+1);
	}
	else{
		a[0]=1;
		return Fill(m-1,n,k-c[m][n-1],a+1);
	}
}

string Calc(int N,int M,unsigned long K){
	for (int i=1;i<=M;i++){
		c[i][0]=1;
	}
	for (int j=1;j<=N;j++){
		c[0][j]=1;
	}
	c[0][0]=0;
	for (int i=1;i<=M;i++){
		for (int j=1;j<=M;j++){
			c[i][j]=c[i-1][j]+c[i][j-1];
		}
	}
	int a[34];
	if (Fill(M,N,K,a)){
		string res;
		for (int i=0;i<=M+N-1;i++){
			res+=a[i]+'0';
		}
		return res;
	}
	else{
		return invStr;
	}

}

int main (){
	cin>>cn;
	int n,m;
	unsigned long k;
	for (int i=0;i<cn;i++){
		cin>>n>>m>>k;
		cout<<Calc(n,m,k)<<endl;
	}
	return 0;
}
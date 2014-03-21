/*
ID: yezhiyo1
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
unsigned int N,L,I;
unsigned int cur=0;




#define MAX_N 31
unsigned int c[MAX_N+1][MAX_N+1];
int a[MAX_N];

void FindOnes(int n,int l,int x){
	int pos=-1;
	for (int i=0;i<=n;i++){
		if (c[i][l]>=x){
			pos=i;
			break;
		}
	}
	if (pos==0){
		if (x==1){
			a[N-1]=0;
		}
		else if (x==2){
			a[N-1]=1;
		}
		else{
			cout<<"error!\n";
		}
		return;
	}
	else{
		a[N-1-pos]=1;
		FindOnes(pos-1,l-1,x-c[pos-1][l]);
	}
}

int main (){
	fin>>N>>L>>I;
	for (int i=1;i<=N;i++){
		c[i][0]=1;
	}
	for (int i=1;i<=L;i++){
		c[0][i]=2;
	}
	c[0][0]=1;
	memset(a,0,sizeof(int)*N);

	if (N==1){
		if (I==1){
			a[N-1]=0;
		}
		else if (I==2){
			a[N-1]=1;
		}
	}

	for (int i=1;i<N;i++){
		for (int j=1;j<=L;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
		if (c[i][L]>=I){
			FindOnes(i,L,I);
			break;
		}
	}

	for (int i=0;i<N;i++){
		fout<<a[i];
	}
	fout<<endl;

	return 0;

}
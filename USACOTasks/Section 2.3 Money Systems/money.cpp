/*
ID: yezhiyo1
PROG: money
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;
ifstream fin("money.in");
ofstream fout("money.out");
int v;
int n;
unsigned long long c[26][10001];
int moneys[26];
int main (){
	fin>>v>>n;
	for (int i=0;i<v;i++){
		fin>>moneys[i];
	}
	for (int i=1;i<=n;i++){
		if (i%moneys[0]==0){
			c[0][i]=1;
		}
		else{
			c[0][i]=0;
		}
	}
	for (int i=0;i<v;i++){
		c[i][0]=1;
	}
	for (int i=1;i<v;i++){
		for (int j=1;j<=n;j++){
			for (int k=0;k*moneys[i]<=j;k++){
				c[i][j]+=c[i-1][j-k*moneys[i]];
			}
		}
	}
	fout<<c[v-1][n]<<endl;
	return 0;
}
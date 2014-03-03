/*
ID: yezhiyo1
PROG: nocows
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;
int k;
int n;
int c[101][201];
int main (){
	ifstream fin("nocows.in");
	ofstream fout("nocows.out");
	fin>>n>>k;

	memset(c[1],0,(n+1)*sizeof(int));
	for (int i=1;i<=k;i++){
		c[i][1]=0;
	}
	c[1][1]=1;
	for (int i=2;i<=k;i++){
		for (int j=3;j<=n;j+=2){		//n
			c[i][j]=0;
			for (int m=1;m<j-1;m+=2){	//every divide
				int rightSum=0;
				for (int p=1;p<=i-1;p++){
					if (p==i-1){				//the redundant while tree structure is the same
						rightSum+=c[p][j-1-m];
					}
					else{
						int temp=(c[p][j-1-m]*2)%9901;
						rightSum+=temp;
					}
					rightSum%=9901;
				}
				int temp=(c[i-1][m]*rightSum)%9901;
				c[i][j]+=temp;
				c[i][j]%=9901;
			}
		}
	}
	fout<<c[k][n]<<endl;
	return 0;
}
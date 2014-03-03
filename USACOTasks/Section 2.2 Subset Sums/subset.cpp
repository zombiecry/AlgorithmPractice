/*
ID: yezhiyo1
PROG: subset
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;
//dp table
long long int c[391][40];

int main(){
	ifstream fin("subset.in");
	ofstream fout("subset.out");
	int n;
	fin>>n;
	int sum=n*(n+1)/2;
	if (sum%2!=0){
		fout<<0<<endl;
		return 0;
	}
	int halfSum=sum/2;
	c[1][1]=1;
	for (int i=2;i<=halfSum;i++){
		c[i][1]=0;
	}
	for (int i=1;i<=n;i++){
		c[1][i]=1;
		c[0][i]=1;
	}
	for (int i=2;i<=halfSum;i++){
		for (int j=2;j<=n;j++){
			if (i>=j){
				c[i][j]=c[i-j][j-1]+c[i][j-1];
			}
			else {
				c[i][j]=c[i][j-1];
			}
		}
	}
	fout<<c[halfSum][n]/2<<endl;
	return 0;
}
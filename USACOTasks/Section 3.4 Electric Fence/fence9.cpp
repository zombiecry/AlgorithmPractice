/*
ID: yezhiyo1
PROG: fence9
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;
ifstream fin("fence9.in");
ofstream fout("fence9.out");
double eps=1e-5;
int m,n,p;

int main(){
	fin>>n>>m>>p;
	double par1=double(n)/double(m);
	double par2=double(n-p)/double(m);
	double par3=p;
	int num=0;
	for (int j=1;j<m;j++){
		double x=par1*j;
		double x1=ceil(x);
		if (fabs(x1-x)<eps){
			x1+=1.0f;
		}
		x=par2*j+par3;
		double x2=floor(x);
		if (fabs(x-x2)<eps){
			x2-=1.0f;
		}
		int ix1=x1;
		int ix2=x2;
		if (ix1<=ix2){
			num+=ix2-ix1+1;
		}
	}
	fout<<num<<endl;
	return 0;
}
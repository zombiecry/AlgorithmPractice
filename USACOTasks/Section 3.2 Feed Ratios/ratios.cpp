/*
ID: yezhiyo1
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("ratios.in");
ofstream fout("ratios.out");
int a[3][4];
int b[4];
int c[4];
int d[4];
int e[4];
long long sol[3][2];
long long result[3];
void Mult(int *dst,int *src,int factor){
	for (int i=0;i<4;i++){
		dst[i]=src[i]*factor;
	}
}
void Minus(int *dst,int *src1,int *src2){
	for (int i=0;i<4;i++){
		dst[i]=src1[i]-src2[i];
	}
}

void Copy(int *dst,int *src){
	memcpy(dst,src,sizeof(int)*4);
}

void CalcSol(int mixIndex){
	int r1=(mixIndex+1)%3;
	int r2=(mixIndex+2)%3;
	if (a[0][r1]==0){
		Copy(d,a[0]);

		Mult(b,a[1],a[2][r1]);
		Mult(c,a[2],a[1][r1]);
		Minus(e,b,c);			//e: without r1
	}
	else{
		Mult(b,a[0],a[1][r1]);	//A1*A2[i]
		Mult(c,a[1],a[0][r1]);	//A2*A1[i]
		Minus(d,b,c);			//d: without r1

		Mult(b,a[0],a[2][r1]);
		Mult(c,a[2],a[0][r1]);
		Minus(e,b,c);			//e: without r1
	}

	if (d[r2]!=0){
		Mult(b,d,e[r2]);
		Mult(c,e,d[r2]);
		Minus(d,b,c);
	}
	else{
		if (d[mixIndex]==0){
			Copy(d,e);
		}
	}
	sol[mixIndex][0]=d[mixIndex];
	sol[mixIndex][1]=d[3];
}
template <class T>
T GCD(T a,T b){
	if (b==0){
		return a;
	}
	return GCD(b,a%b);
}

int main (){
	for (int i=0;i<3;i++){
		fin>>a[i][3];
	}


	for (int i=0;i<3;i++){
		for (int j=0;j<3;j++){
			fin>>a[j][i];
		}
	}

	for (int i=0;i<3;i++){
		CalcSol(i);
		if (sol[i][0]*sol[i][1]<0){
			fout<<"NONE"<<endl;
			return 0;
		}
		int gcd=GCD(sol[i][0],sol[i][1]);
		sol[i][0]/=gcd;
		sol[i][1]/=gcd;
	}
	long long gcd=0;
	for (int i=0;i<3;i++){
		result[i]=sol[i][1];
		for (int j=0;j<3;j++){
			if (i!=j){
				result[i]*=sol[j][0];
			}
		}
		gcd=GCD(result[i],gcd);
	}
	for (int i=0;i<3;i++){
		result[i]/=gcd;	
	}
	int k=1;
	int factor=1;
	for (int i=0;i<3;i++){
		if (a[i][3]){
			unsigned int num=0;
			for (int j=0;j<3;j++){
				num+=result[j]*a[i][j];
			}
			if (num<a[i][3]){
				factor=a[i][3]/num;
				num*=factor;
			}
			k=num/a[i][3];
			break;
		}
	}

	for (int i=0;i<3;i++){
		result[i]*=factor;	
		fout<<result[i]<<" ";
	}

	fout<<k<<endl;


	return 0;
}
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
int N,L,I;
unsigned int cur=0;
bool CheckNum(unsigned a){
	int count=0;
	for (int i=0;i<N;i++){
		if(a & 0x1){
			count++;
			if (count>L){
				return false;
			}
		}
		a=a>>1;
	}
	return true;
}
#define MAX_N 31
#define MAX_L 31
int c[MAX_N+1][MAX_L+1];

int main (){
	fin>>N>>L>>I;

	for (int i=1;i<=N;i++){
		c[i][1]=i+1;
	}
	for (int i=1;i<=L;i++){
		c[1][i]=2;
	}
	bool findFlag=false;
	int n,l;
	for (int i=2;i<=N;i++){
		for (int j=2;j<=L;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
		if (c[i][L]>=I){
			n=i;
			l=L;
			findFlag=true;
			break;
		}
	}

	if (!findFlag){
		n=N;
		l=L;
	}
	int cur=0;
	unsigned int maxNum=1;
	for (int k=0;k<L-1;k++){
		maxNum=maxNum<<1;
		maxNum++;
	}
	for (int k=0;k<n-L;k++){
		maxNum=maxNum<<1;
	}
	int count=c[n][l];
	cur=maxNum;
	while(count>I){
		maxNum--;
		if(CheckNum(maxNum)){
			cur=maxNum;
			count--;
		}
	}
	std::vector <int> nums;
	for (int k=0;k<N;k++){
		nums.push_back(cur & 0x1);
		cur=cur>>1;
	}
	for (int k=N-1;k>=0;k--){
		fout<<nums[k];
	}
	fout<<endl;
	return 0;

}
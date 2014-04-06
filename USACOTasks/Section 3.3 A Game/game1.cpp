/*
ID: yezhiyo1
PROG: game1
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
#include <memory.h>
using namespace std;
ifstream fin("game1.in");
ofstream fout("game1.out");
const int MAX_N = 100;
int N;
std::vector <int> v;
int				  total=0;
int c[MAX_N][MAX_N+1];

void CalcSum(int &leftSum,int &rightSum,int start,int end){
	leftSum=0;
	rightSum=0;
	for (int i=start;i<=end;i++){
		if (i!=start){
			rightSum+=v[i];
		}
		if (i!=end){
			leftSum+=v[i];
		}
	}
}

int main (){
	fin>>N;
	v.resize(N);
	for (int i=0;i<N;i++){
		fin>>v[i];
		total+=v[i];
	}
	
	for (int i=0;i<=N-1;i++){
		c[i][1]=v[i];
	}

	for (int j=2;j<=N;j++){
		for (int i=0;i<=N-j;i++){
			int leftSum;
			int rightSum;
			CalcSum(leftSum,rightSum,i,i+j-1);
			int a=v[i]    +rightSum-c[i+1][j-1];
			int b=v[i+j-1]+leftSum -c[i][j-1];
			c[i][j]=std::max(a,b);
		}
	}
	fout<<c[0][N]<<" "<<total-c[0][N]<<endl;
	return 0;
}
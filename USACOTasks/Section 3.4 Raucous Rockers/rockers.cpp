/*
ID: yezhiyo1
PROG: rockers
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
ifstream fin("rockers.in");
ofstream fout("rockers.out");
const int MAX_N = 20;
const int MAX_M = 20;
int N,T,M;
std::vector <bool> inserted;
std::vector <int>  songs;
int a[MAX_N][MAX_N];		//[i,j)
int c[MAX_M+1][MAX_N+1];

int Calc(int start,int len){
	std::vector <int> nums;
	nums.resize(len);
	for (int i=0;i<len;i++){
		nums[i]=songs[i+start];
	}
	std::sort(nums.begin(),nums.end());
	int count=0;
	int left=T;
	for (int i=0;i<len;i++){
		if (left>=nums[i]){
			left-=nums[i];
			count++;
		}
		else{
			break;
		}
	}
	return count;
}

int main (){
	fin>>N>>T>>M;
	inserted.resize(N,false);
	songs.resize(N);
	for (int i=0;i<N;i++){
		fin>>songs[i];
	}
	for (int j=1;j<=N;j++){
		for (int i=0;i<N;i++){
			if (i+j<=N){
				a[i][j]=Calc(i,j);
			}
		}
	}
	for (int i=0;i<N;i++){
		c[1][i]=a[0][i+1];
	}
	for (int i=2;i<=M;i++){
		for (int j=0;j<N;j++){
			c[i][j]=c[i-1][j];
			for (int k=0;k<j;k++){
				c[i][j]=std::max(c[i][j],c[i-1][k]+a[k+1][j-k]);
			}
		}
	}
	fout<<c[M][N-1]<<endl;
	return 0;
}
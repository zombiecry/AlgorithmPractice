/*
ID: yezhiyo1
PROG: stamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("stamps.in");
ofstream fout("stamps.out");
int K,N;
#define MAX_K    200
#define MAX_ITEM 10000
#define MAX_N    50
int c[MAX_ITEM*MAX_K+1];
std::vector <int> nums;
int maxNum=0;

int main (){
	fin>>K>>N;
	nums.resize(N);
	for (int i=0;i<N;i++){
		fin>>nums[i];
		if (nums[i]>maxNum){
			maxNum=nums[i];
		}
	}
	c[0]=0;
	int maxInt=maxNum*K;
	std::sort(nums.begin(),nums.end());
	int maxConNum=0;
	int curConNum=0;
	for (int i=1;i<=maxInt;i++){
		c[i]=K+1;
		for (int j=0;j<N;j++){
			if (i-nums[j]>=0){
				c[i]=std::min(c[i],c[i-nums[j]]+1);
			}
			else{
				break;
			}
		}
		if (c[i]<=K){
			curConNum++;
		}
		else{
			maxConNum=std::max(maxConNum,curConNum);
			curConNum=0;
		}
	}
	maxConNum=std::max(maxConNum,curConNum);
	fout<<maxConNum<<endl;
	return 0;
}
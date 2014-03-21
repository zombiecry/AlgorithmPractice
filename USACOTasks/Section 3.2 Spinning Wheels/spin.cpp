/*
ID: yezhiyo1
PROG: spin
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("spin.in");
ofstream fout("spin.out");
int v[5];
int T[5];
struct Wedge{
	int start;
	int extent;
};
std::vector <Wedge> wedges[5];


int a[360];
void Fill(int start,int end){
	if (end>=360){
		for (int i=start;i<360;i++){
			a[i]++;
		}
		for (int i=0;i<=end%360;i++){
			a[i]++;
		}
	}
	else{
		for (int i=start;i<=end;i++){
			a[i]++;
		}
	}
}
int main (){
	for (int i=0;i<5;i++){
		fin>>v[i];
		int wedgeNum;
		fin>>wedgeNum;
		wedges[i].resize(wedgeNum);
		for (int j=0;j<wedgeNum;j++){
			fin>>wedges[i][j].start>>wedges[i][j].extent;
		}
	}
	int minTime=-1;
	for (int i=0;i<360;i++){			//time
		memset(a,0,sizeof(int)*360);
		for (int j=0;j<5;j++){
			for (int k=0;k<wedges[j].size();k++){
				int start=wedges[j][k].start+v[j]*i;
				start%=360;
				int end=start+wedges[j][k].extent;
				Fill(start,end);
			}
		}
		for (int j=0;j<360;j++){
			if (a[j]>=5){
				minTime=i;
				break;
			}
		}
		if (minTime!=-1){
			break;
		}
	}
	if (minTime==-1){
		fout<<"none"<<endl;
	}
	else{
		fout<<minTime<<endl;
	}

	return 0;
}
/*
ID: yezhiyo1
PROG: camelot
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("usacodatashow.txt");
ofstream fout("camelot.out");
int R,C;
const int MAX_R = 30;
const int MAX_C = 26;
const int INF = 0xfffffff;
int c[MAX_R*MAX_C][MAX_R*MAX_C];
int kinX,kinY;

int n;
int knightNum;
std::vector <int> knightX;
std::vector <int> knightY;


std::vector <int> kingDist;

#define GETX(idx)		\
	(idx%C)
#define GETY(idx)       \
	(idx/C)
#define GETINDEX(x,y)	\
	(x+y*C)

bool KnightConnect(int v1,int v2){
	int x1=GETX(v1);
	int y1=GETY(v1);
	int x2=GETX(v2);
	int y2=GETY(v2);
	if (abs(x1-x2)==1){
		if (abs(y1-y2)==2){
			return true;
		}
	}
	else if (abs(x1-x2)==2){
		if (abs(y1-y2)==1){
			return true;
		}
	}
	return false;
}


int main(){
	fin>>R>>C;
	n=R*C;
	char a;
	int  b;
	fin>>a>>b;
	kinX=a-'A';
	kinY=b-1;
	while (fin>>a>>b){
		//cout<<a<<endl;
		if (a>='A' && a<='Z'){
			int x=a-'A';
			int y=b-1;
			knightX.push_back(x);
			knightY.push_back(y);
		}
	}
	knightNum=knightX.size();
	n=R*C;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (KnightConnect(i,j)){
				c[i][j]=1;
			}
			else{
				c[i][j]=INF;
			}
		}
		c[i][i]=0;
	}

	for (int k=0;k<n;k++){
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				c[i][j]=std::min(c[i][j],c[i][k]+c[k][j]);
			}
		}
	}
	kingDist.resize(n);
	for (int i=0;i<n;i++){
		kingDist[i]=std::max(abs(GETX(i)-kinX),abs(GETY(i)-kinY));
	}

	int minSum=INF;
	for (int i=0;i<n;i++){
		int distSum=0;
		for (int j=0;j<knightNum;j++){
			int index=GETINDEX(knightX[j],knightY[j]);
			distSum+=c[index][i];
		}
		int sum=distSum+kingDist[i];	//king move by itself
		for (int j=0;j<knightNum;j++){	//king move by one knight
			int index=GETINDEX(knightX[j],knightY[j]);
			int resDist=distSum-c[index][i];
			int minMidDist=INF;
			for (int k=0;k<n;k++){
				minMidDist=std::min(minMidDist,c[index][k]+c[k][i]+kingDist[k]);
			}
			sum=std::min(sum,minMidDist+resDist);
		}
		minSum=std::min(minSum,sum);
	}
	fout<<minSum<<endl;
	return 0;
}
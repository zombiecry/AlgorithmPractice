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
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("camelot.in");
ofstream fout("camelot.out");
int R,C;
const int MAX_R = 30;
const int MAX_C = 26;
const int PAREA = 5;
const int INF = 0xfffffff;
int c[MAX_R*MAX_C][MAX_R*MAX_C];
int dist[MAX_R*MAX_C][MAX_R*MAX_C];
int kinX,kinY;
int kingIndex;

int n;
int knightNum;

std::vector <int> knights;
std::vector <int> kingDist;
std::vector <int> kingArea;
std::vector <int> knightDistSum;
int kingAreaNum;

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

//for bfs
int						   *distArray;
std::vector <bool>          visited;


void FloodFill(int src){
	for (int i=0;i<n;i++){
		distArray[i]=INF;
	}
	distArray[src]=0;
	visited.assign(n,false);
	visited[src]=true;
	std::queue <int> que;
	que.push(src);
	while (!que.empty()){
		int u=que.front();
		que.pop();
		for (int v=0;v<n;v++){
			if (c[u][v]<INF){
				if (!visited[v]){
					que.push(v);
					distArray[v]=distArray[u]+1;
					visited[v]=true;
				}
			}
		}
	}
}

int main(){
	fin>>R>>C;
	n=R*C;
	char a;
	int  b;
	fin>>a>>b;
	kinX=a-'A';
	kinY=b-1;
	kingIndex=GETINDEX(kinX,kinY);
	while (fin>>a>>b){
		if (a>='A' && a<='Z'){
			int x=a-'A';
			int y=b-1;
			knights.push_back(GETINDEX(x,y));
		}
	}
	knightNum=knights.size();
	n=R*C;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (KnightConnect(i,j)){
				c[i][j]=1;
			}
			else{
				c[i][j]=INF;
			}
			dist[i][j]=c[i][j];
		}
		c[i][i]=0;
		dist[i][i]=0;

	}
	for (int i=-PAREA;i<=PAREA;i++){
		for (int j=-PAREA;j<=PAREA;j++){
			int x=kinX+i;
			int y=kinY+j;
			if (x>=0 && x<C &&
				y>=0 && y<R){
                int index=GETINDEX(x,y);
				kingArea.push_back(index);
			}
		}
	}
	kingAreaNum=kingArea.size();
	kingDist.resize(n);
	for (int i=0;i<n;i++){
		kingDist[i]=std::max(abs(GETX(i)-kinX),abs(GETY(i)-kinY));
	}
	std::set <int> calcedPoints;
	visited.resize(n);
	for (int i=0;i<knightNum;i++){
		distArray=dist[knights[i]];
		FloodFill(knights[i]);
		calcedPoints.insert(knights[i]);
	}
	for (int i=0;i<kingAreaNum;i++){
		if (calcedPoints.count(kingArea[i])==0){
			distArray=dist[kingArea[i]];
			FloodFill(kingArea[i]);
		}
	}
	knightDistSum.resize(n);
	for (int i=0;i<n;i++){
		int sum=0;
		for (int j=0;j<knightNum;j++){
			sum+=dist[knights[j]][i];
		}
		knightDistSum[i]=sum;
	}
	int ms=INF;
	int minSum=INF;
	for (int i=0;i<n;i++){
		int sum=knightDistSum[i]+kingDist[i];	//king move by itself
		for (int j=0;j<knightNum;j++){			//king move by one knight
			int knightIndex=knights[j];
			int resDist=knightDistSum[i]-dist[knightIndex][i];
			ms=std::min(resDist,ms);
			int minMidDist=INF;
			for (int k=0;k<kingAreaNum;k++){	//the finite king's neibor area
				int candiIndex=kingArea[k];
				minMidDist=std::min(minMidDist,dist[knightIndex][candiIndex]+dist[candiIndex][i]+kingDist[candiIndex]);
			}
			sum=std::min(sum,minMidDist+resDist);
		}
		minSum=std::min(minSum,sum);
	}
	fout<<minSum<<endl;
	return 0;
}
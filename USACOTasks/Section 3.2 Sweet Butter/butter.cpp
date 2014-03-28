/*
ID: yezhiyo1
PROG: butter
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("butter.in");
ofstream fout("butter.out");
int N,P,C;
#define P_MAX 800
#define N_MAX 500
#define MAX_UINT 0x0fffffff


struct Edge{
	int to;
	int cost;
	int next;
	Edge (int _to,int _cost,int _next):to(_to),cost(_cost),next(_next){}
};
std::vector <Edge> edges;
std::vector <int>  pres;

void InsertEdge(int u,int v,int cost,vector <Edge> &edges,vector <int> &pres){
	Edge newEdge(v,cost,-1);
	edges.push_back(newEdge);
	if (pres[u]==-1){	//first
		pres[u]=edges.size()-1;
	}
	else{				//add front
		int i=pres[u];
		for (;edges[i].next!=-1;i=edges[i].next){
			volatile int t=1;
		}
		edges[i].next=edges.size()-1;
	}
}

std::vector <int> cows;
std::vector <unsigned int> distSum;

//for dijsktra alg
std::vector <int>		   sortArray;		//we proceed heap
std::vector <int>		   heapPos;
int						   heapNum;
std::vector <unsigned int> dist;
bool DijCompare(int a,int b){
	return dist[a]>dist[b];
}


void ShiftDown(int index){
	sortArray[0]=sortArray[index];
	int i=index;
	int child=i*2;
	for (;child<=heapNum;){
		if (child+1<=heapNum){
			child=(DijCompare(sortArray[child],sortArray[child+1]))?child+1:child;
		}
		if (DijCompare(sortArray[child],sortArray[0])){	//smaller child bigger than it
			break;
		}
		sortArray[i]=sortArray[child];
		heapPos[sortArray[i]]=i;
		i=child;
		child=i*2;
	}
	sortArray[i]=sortArray[0];
	heapPos[sortArray[i]]=i;
}

void ShiftUp(int index){
	sortArray[0]=sortArray[index];
	int i=index;
	int father=i/2;
	for (;father>0;){
		if (!DijCompare(sortArray[father],sortArray[0])){
			break;
		}
		sortArray[i]=sortArray[father];
		heapPos[sortArray[i]]=i;
		i=father;
		father=i/2;
	}
	sortArray[i]=sortArray[0];
	heapPos[sortArray[i]]=i;
}

int DeleteMin(){
	int result=sortArray[1];
	heapPos[result]=-1;
	sortArray[1]=sortArray[heapNum];
	heapPos[sortArray[1]]=1;
	heapNum--;
	ShiftDown(1);
	return result;
}



#define USE_HEAP 1

void SP(int src,int cowNum){
	for (int i=0;i<P;i++){
		sortArray[i+1]=i;
		heapPos[i]=i+1;
		dist[i]=MAX_UINT;
	}
	dist[src]=0;
#if USE_HEAP
	heapNum=P;
	ShiftUp(heapPos[src]);
#endif
	int count=P;
	while (count>0){
#if USE_HEAP
		int u=DeleteMin();
#else
		std::sort(sortArray.begin()+1,sortArray.begin()+count+1,DijCompare);
		int u=sortArray[count];
#endif
		count--;
		for (int i=pres[u];i!=-1;i=edges[i].next){
			int v=edges[i].to;
			int cost=edges[i].cost;
#if USE_HEAP
			if (dist[v]>(dist[u]+cost)){
				dist[v]=dist[u]+cost;
				ShiftUp(heapPos[v]);
			}
#else
			dist[v]=std::min(dist[v],dist[u]+cost);
#endif
		}
	}

	for (int i=0;i<P;i++){
		distSum[i]+=dist[i]*cowNum;
	}
}


int main (){

	fin>>N>>P>>C;
	pres.resize(P,-1);
	cows.resize(P,0);
	sortArray.resize(P+1);
	heapPos.resize(P);
	dist.resize(P);
	distSum.resize(P,0);
	for (int i=0;i<N;i++){
		int u;
		fin>>u;
		cows[u-1]++;
	}

	for (int i=0;i<C;i++){
		int u,v,cost;
		fin>>u>>v>>cost;
		InsertEdge(u-1,v-1,cost,edges,pres);
		InsertEdge(v-1,u-1,cost,edges,pres);
	}


	for (int i=0;i<P;i++){
		if (cows[i]){
			SP(i,cows[i]);
		}
	}
	unsigned int minSum=0xffffffff;
	for (int i=0;i<P;i++){
		minSum=std::min(minSum,distSum[i]);
	}
	fout<<minSum<<endl;
	return 0;
}
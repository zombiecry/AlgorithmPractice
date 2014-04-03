/*
ID: yezhiyo1
PROG: fence
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
ifstream fin("fence.in");
ofstream fout("fence.out");

const int MAX_F=1024;
const int MAX_INTER=500;
int F;
struct Edge{
	int to;
	int next;
	Edge(){}
	Edge(int _to,int _next):to(_to),next(_next){}
};

std::vector <Edge> edges;
std::vector <int>  pres;
int m=0;
int n=0;
void InsertFence(int u,int v){
	n=std::max(n,u);
	n=std::max(n,v);
	edges[m]=Edge(v,-1);
	m++;
	if (pres[u]==-1){
		pres[u]=m-1;
	}
	else{
		int i=pres[u];
		for (;edges[i].next!=-1;i=edges[i].next){
			volatile int temp=1;
		}
		edges[i].next=m-1;
	}
}

int main (){
	fin>>F;
	edges.resize(F*2);
	pres.resize(MAX_INTER,-1);
	for (int i=0;i<F;i++){
		int u,v;
		fin>>u>>v;
		InsertFence(u-1,v-1);
		InsertFence(v-1,u-1);
	}
	//find the start
	int maxEndVert=-1;
	for (int i=0;i<n;i++){
		int vertCount=0;
		for (int j=pres[i];j!=-1;j=edges[j].next){
			vertCount++;
		}
		if (vertCount % 2==1){
			maxEndVert=i;
		}
	}
	//euler finding algorithm
	std::vector <bool> edgeAvail(n,true);
	std::vector <int>  eulerTour;
	stack <int> st;
	st.push(maxEndVert);
	while (!st.empty()){
		int u=st.top();
		int minV=MAX_INTER+2;
		int minVEdge=-1;
		for (int i=pres[u];i!=-1;i=edges[i].next){
			if (edgeAvail[i]){
				int v=edges[i].to;
				if (v<minV){
					minV=v;
					minVEdge=i;
				}
			}
		}
		if (minV==MAX_INTER+2){
			eulerTour.push_back(u);
			st.pop();
		}
		else{
			st.push(minV);
			edgeAvail[minVEdge]=false;
		}
	}
	for (int i=0;i<eulerTour.size();i++){
		fout<<eulerTour[i]<<endl;
	}
	return 0;
}
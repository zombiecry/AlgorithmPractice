#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;
#if 1
ifstream fin("fetch.in");
ofstream fout("fetch.out");
#define cin fin
#define cout fout
#endif
#ifdef __GNUC__
#define tr(container, it) \
	for (typeof(container.begin()) it = container.begin(); it != container.end();it++)

#define trCheck(container, it) \
	for (typeof(container.begin()) it = container.begin(); it != container.end();)

#else
#ifdef _MSC_VER
#define tr(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();it++)
#define trCheck(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();)

#endif
#endif
typedef pair<int,int> scPair2i;


int m,n;
int cn;
const int MAX_MN = 100;
const int INF = 0xfffffff;
int   c[MAX_MN][MAX_MN];

struct Edge{
	int cost;
	int from;
	int to;
	int next;
	Edge(int _from,int _to,int _cost,int _next):from(_from),to(_to),cost(_cost),next(_next){}
	Edge (){}
};

vector <Edge> edges;
vector <int>  pres;

void Insert(int u,int v,int cost){
	edges.push_back(Edge(u,v,cost,-1));
	if (pres[u]==-1){
		pres[u]=edges.size()-1;
	}
	else{
		int i=pres[u];
		for (;edges[i].next!=-1;i=edges[i].next){
			volatile int temp=1;
		}
		edges[i].next=edges.size()-1;
	}
}
bool EdgeCompare(int e1,int e2){
	return edges[e1].cost>edges[e2].cost;
}
int CalcSum(){
	edges.resize(0);
	pres.resize(0);
	pres.resize(n+m,-1);
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			int u=j;
			int v=n+i;
			int cost=c[i][j];
			Insert(u,v,cost);
			Insert(v,u,cost);
		}
	}
	set <scPair2i> que;
	vector <int>   primCost(m+n,INF);
	vector <int>   primPres(m+n,-1);
	vector <int>   primEdge(m+n,-1);
	vector <bool>  primDel(m+n,false);
	primCost[0]=0;
	que.insert(scPair2i(0,0));

	while (!que.empty()){
		scPair2i top=*que.begin();
		int u=top.second;
		que.erase(que.begin());
		primDel[u]=true;
		for (int i=pres[u];i!=-1;i=edges[i].next){
			int v=edges[i].to;
			int cost=edges[i].cost;
			if (primDel[v]){
				continue;
			}
			if (cost < primCost[v]){
				if (primCost[v]!=INF){
					que.erase(que.find(scPair2i(primCost[v],v)));
				}
				primCost[v]=cost ;
				primPres[v]=u;
				primEdge[v]=i;
				que.insert(scPair2i(primCost[v],v));
			}
		}
	}
	primCost.assign(m+n,0);
	vector <int> newEdges;
	for (int i=0;i<m+n;i++){
		if (primEdge[i]!=-1){
			int u=edges[primEdge[i]].from;
			int v=edges[primEdge[i]].to;
			primCost[u]++;
			primCost[v]++;
			newEdges.push_back(primEdge[i]);
		}
	}

	sort(newEdges.begin(),newEdges.end(),EdgeCompare);
	for (int i=0;i<newEdges.size();i++){
		int u=edges[newEdges[i]].from;
		int v=edges[newEdges[i]].to;
		if (primCost[u]>1 && primCost[v]>1){
			newEdges[i]=-1;
			primCost[u]--;
			primCost[v]--;
		}
	}
	int sum=0;
	for (int i=0;i<newEdges.size();i++){
		if (newEdges[i]!=-1){
			sum+=edges[newEdges[i]].cost;
		}
	}
	return sum;
}


int main (){
	cin>>cn;
	for (int i=0;i<cn;i++){
		cin>>m>>n;
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				cin>>c[i][j];
			}
		}
		cout<<"Case "<<i+1<<": "<<CalcSum()<<endl;
	}
	return 0;
}
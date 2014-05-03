#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;

#define DEBUG_FLAG 1
#if DEBUG_FLAG
ifstream fin("shu.in");
ofstream fout("shu.out");
#define cin fin
#define cout fout
#endif
//
typedef long long ll;
#define tr(container,it)		\
	for (it=container.begin();it!=container.end();it++)
typedef std::pair <int,int> scPair2i;
int T;

//data
int N;
int Q;
int u,l,r;
ll delta;
//////


struct Node{
	vector <int> childs;
	ll  weight;
	int depth;
	Node (){
		weight=0;
		depth=-1;
	}
};
vector <Node> nodes;


void AddChild(int father, int child){
	Node &cur=nodes[father];
	cur.childs.push_back(child);
}
void Op(int root){
	Node &cur=nodes[root];
	if (nodes[root].depth>=l &&
		nodes[root].depth<=r){
			nodes[root].weight+=delta;
	}
	for (int i=0;i<cur.childs.size();i++){
		Op(cur.childs[i]);
	}
}
const ll MOD=1000000007;
const ll MAGIC=12347;
ll CalcHash(){
	ll hashNum=0;
	for (int i=0;i<nodes.size();i++){
		ll temp1=(hashNum*MAGIC)%MOD;
		ll temp2=(nodes[i].weight)%MOD;
		hashNum=(temp1+temp2)%MOD;
	}
	return hashNum;
}

void CalcDepth(int root){
	for (int i=0;i<nodes[root].childs.size();i++){
		int child=nodes[root].childs[i];
		nodes[child].depth=nodes[root].depth+1;
	}
	for (int i=0;i<nodes[root].childs.size();i++){
		CalcDepth(nodes[root].childs[i]);
	}
}

int main (){
	cin>>T;
	for (int i=0;i<T;i++){
		cin>>N;
		nodes.resize(0);
		nodes.resize(N);
		
		for (int j=1;j<=N-1;j++){
			int father;
			cin>>father;
			AddChild(father-1,j);
		}
		nodes[0].depth=1;
		CalcDepth(0);
		cin>>Q;
		for (int j=0;j<Q;j++){
			cin>>u>>l>>r>>delta;
			Op(u-1);
		}
		cout<<"Case "<<i+1<<": "<<CalcHash()<<endl;
	}
	return 0;
}
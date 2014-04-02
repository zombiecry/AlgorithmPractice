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
const int MAX_INTER=501;
int F;
int e[MAX_INTER][MAX_INTER];

int main (){
	fin>>F;
	for (int i=0;i<MAX_INTER;i++){
		for (int j=0;j<MAX_INTER;j++){
			e[i][j]=0;
		}
	}
	int n=0;
	for (int i=0;i<F;i++){
		int u,v;
		fin>>u>>v;
		e[u-1][v-1]++;
		e[v-1][u-1]++;
		n=std::max(n,u);
		n=std::max(n,v);
	}
	int startNode=-1;
	for (int i=n-1;i>=0;i--){
		int degree=0;
		for (int j=0;j<n;j++){
			degree+=e[i][j];
		}
		if (degree % 2 ==1){
			startNode=i;
		}
	}
	if (startNode==-1){
		startNode=0;
	}
	std::vector <int> circle;
	stack <int> st;
	st.push(startNode);
	while (!st.empty()){
		int u=st.top();
		int v=-1;
		for (int i=0;i<n;i++){
		//for (int i=n-1;i>=0;i--){
			if (e[u][i]){
				v=i;
				break;
			}
		}
		if (v==-1){	//no nei
			circle.push_back(u);
			st.pop();
		}
		else{
			st.push(v);
			e[u][v]--;
			e[v][u]--;
		}
	}

	for (int i=circle.size()-1;i>=0;i--){
		fout<<circle[i]+1<<endl;
	}
	return 0;
}
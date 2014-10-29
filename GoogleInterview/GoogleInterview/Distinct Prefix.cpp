#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include<queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;
struct Edge{
	char ch;
	int to;
	Edge(char _ch,int _to):ch(_ch),to(_to){}
};
vector<vector<Edge>> g;
int n=4;
vector<string> tot;

void Insert(string &s){
	int cur=0;
	for(int i=0;i<s.length();i++){
		bool found=false;
		for(int j=0;j<g[cur].size();j++){
			Edge &e=g[cur][j];
			if(e.ch==s[i]){
				cur=e.to;
				found=true;
				break;
			}
		}
		if (found) continue;
		g.push_back(vector<Edge>());
		Edge e(s[i],g.size()-1);
		g[cur].push_back(e);
		cur=g.size()-1;
	}
}
string word;
string curPrefix;
bool   isPre;
void DFS(int cur){
	if (!isPre) {
		if (g[cur].size()<=1) {
			isPre=true;
			curPrefix=word;
		}
	}
	if (g[cur].size()==0) { //leaf
		string res=word+" : "+curPrefix;
		tot.push_back(res);
		return;
	}
	for(int i=0;i<g[cur].size();i++){
		word+=g[cur][i].ch;
		DFS(g[cur][i].to);
		isPre=false;
		word.pop_back();
	}
}
int main (){
	//string input[]={"zebra", "dog", "duck","dot"};
	string input[]={"zebra", "dog", "duck", "dove"};
	vector<Edge> s;
	g.push_back(s);
	for(int i=0;i<n;i++){
		Insert(input[i]);
	}
	isPre=false;
	DFS(0);
	vector<string> res=tot;
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
	return 0;
}
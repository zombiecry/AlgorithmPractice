/*
ID: yezhiyo1
LANG: C++
TASK: comehome
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream fin("comehome.in");
ofstream fout("comehome.out");
int n;
struct Path{
	int to;
	int len;
	int nextPath;
	Path(int _to,int _len,int _nextPath):to(_to),len(_len),nextPath(_nextPath){}
};
std::vector <Path> paths;
std::vector <int> pres;
std::vector	<bool> cows;

//for dijsktra
std::vector <long long> costs;
std::vector <int> verts;	//for sort
bool MyCompare(int i,int j){
	return costs[i]>costs[j];
}

char AddCow(char v){
	if (v>='A' && v<='Z'){
		cows[v-'A'+26]=true;
		return v-'A'+26;
	}
	return v-'a';
}

void AddPath(int v1,int v2,int len){
	if (pres[v1]==-1){
		paths.push_back(Path(v2,len,-1));
		pres[v1]=paths.size()-1;
	}
	else{
		int i=pres[v1];
		for (;paths[i].nextPath!=-1;){
			i=paths[i].nextPath;
		}
		paths.push_back(Path(v2,len,-1));
		paths[i].nextPath=paths.size()-1;
	}
}
#define MAX_NUM 0x7fffffff


int main(){
	pres.resize(52,-1);
	cows.resize(52,false);
	fin>>n;
	for (int i=0;i<n;i++){
		char v1,v2;
		int len;
		fin>>v1>>v2>>len;
		v1=AddCow(v1);
		v2=AddCow(v2);
		AddPath(v1,v2,len);
		AddPath(v2,v1,len);
	}
	costs.resize(52,MAX_NUM);
	for (int i=0;i<52;i++){
		if (pres[i]!=-1){
			verts.push_back(i);
		}
	}
	int count=verts.size();
	if (verts[count-1]!=51){
		cout<<"error!"<<endl;
	}
	costs[verts[count-1]]=0;
	while (count>0){
		std::sort(verts.begin(),verts.begin()+count,MyCompare);
		int last=verts[count-1];
		for (int i=pres[last];i!=-1;i=paths[i].nextPath){
			costs[paths[i].to]=std::min(costs[paths[i].to],costs[last]+paths[i].len);
		}
		count--;
	}
	int minCost=MAX_NUM;
	int minVert=-1;
	for (int i=0;i<51;i++){
		if (costs[i]<minCost && cows[i]){
			minCost=costs[i];
			minVert=i;
		}
	}
	fout<<char (minVert-26+'A')<<" "<<minCost<<endl;
	return 0;
}
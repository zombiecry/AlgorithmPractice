/*
ID: yezhiyo1
PROG: agrinet
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("agrinet.in");
ofstream fout("agrinet.out");
#define MAX_DIST 100001
int n;
int con[100][100];

std::vector <int> costs;
std::vector <int> verts;
bool MyCompare(int v1,int v2){
	return costs[v1]>costs[v2];
}

int main (){
	fin>>n;
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			fin>>con[i][j];
		}
	}
	int count=n;
	costs.resize(n,MAX_DIST);
	verts.resize(n);
	for (int i=0;i<n;i++){
		verts[i]=i;
	}
	costs[count-1]=0;
	long long minCost=0;
	while (count>0){
		std::sort(verts.begin(),verts.begin()+count,MyCompare);
		int minVert=verts[count-1];
		for (int i=0;i<n;i++){
			if (con[minVert][i]<costs[i] && i!=minVert){
				costs[i]=con[minVert][i];
			}
		}
		minCost+=costs[minVert];
		count--;
	}
	fout<<minCost<<endl;
	return 0;
}
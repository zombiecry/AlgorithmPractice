/*
ID: yezhiyo1
LANG: C++
TASK: cowtour
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream fin("cowtour.in");
ofstream fout("cowtour.out");
int n;

typedef double scReal;


typedef vector <scReal> scVec;
typedef vector <int> scVeci;
typedef vector <scVeci> scVec2i;
scVec xVec;
scVec yVec;
scVeci vSet;
scVeci vFlags;
int con[150][150];
scReal c[150][150];
scReal diams[150];


scReal Dist(int v1,int v2){
	scReal d1=xVec[v1]-xVec[v2];
	scReal d2=yVec[v1]-yVec[v2];
	return sqrt(d1*d1+d2*d2);
}
scReal Diameter(int v){
	scReal lagestV=0;
	for (int i=0;i<n;i++){
		if (vFlags[i]==vFlags[v] && i!=v){
			if (c[v][i]>lagestV){
				lagestV=c[v][i];
			}
		}
	}
	return lagestV;
}

int main (){
	fin>>n;
	xVec.resize(n);
	yVec.resize(n);
	vFlags.resize(n,-1);
	for (int i=0;i<n;i++){
		fin>>xVec[i]>>yVec[i];
	}
	char ch;
	for (int i=0;i<n;i++){
		fin.get(ch);
		for (int j=0;j<n;j++){
			fin.get(ch);
			if(ch=='0'){
				con[i][j]=0;
				c[i][j]=1e20;
			}
			else{
				con[i][j]=1;
				c[i][j]=Dist(i,j);
			}
		}
		c[i][i]=0;
	}

	//build connectivity,dfs
	int tag=0;
	while (true){
		bool left=false;
		for (int i=0;i<n;i++){
			if (vFlags[i]==-1){
				vSet.push_back(i);
				left=true;
				break;
			}
		}
		if (!left){
			break;
		}
		//dfs
		while (!vSet.empty()){
			int top=vSet[vSet.size()-1];
			vFlags[top]=tag;
			vSet.pop_back();
			for (int i=0;i<n;i++){
				if (i!=top && con[top][i] && vFlags[i]==-1){
					vSet.push_back(i);
				}
			}
		}
		tag++;
	}
	//floyd alg
	for (int k=0;k<n;k++){
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				c[i][j]=std::min(c[i][j],c[i][k]+c[k][j]);
			}
		}
	}
	scReal lagestDDiam=0;
	for (int i=0;i<n;i++){
		diams[i]=Diameter(i);
		if (diams[i]>lagestDDiam){
			lagestDDiam=diams[i];
		}
	}
	//permutation
	scReal smallDiam=1e20;	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (vFlags[i]!=vFlags[j]){
				scReal diam=diams[i]+Dist(i,j)+diams[j];
				if (diam<smallDiam){
					smallDiam=diam;
				}
			}
		}
	}
	fout.setf(std::ios::fixed,ios::floatfield);
	fout.precision(6);
	fout<<max(lagestDDiam,smallDiam)<<endl;

	return 0;
}
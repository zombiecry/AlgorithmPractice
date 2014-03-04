/*
ID: yezhiyo1
LANG: C++
TASK: maze1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("maze1.in");
ofstream fout("maze1.out");
int w,h;
char orgGraph[2*100+1][2*38+1];

struct Edge{
	int to;
	int nextEdge;
	Edge(int _to,int _nextEdge):to(_to),nextEdge(_nextEdge){}
};
vector <Edge> edges;
vector <int>  pres;

//for dijsktra
int len;
vector <int> costs1;
vector <int> costs2;
vector <int> vertIdx; //for sort
vector <int> *pCosts;



bool MyCompare(const int &i,const int &j){
	return (*pCosts)[i]>(*pCosts)[j];
}


void CalcCost(int src,vector <int> &costs){
	costs.assign(len,9999);
	costs[src]=0;
	for (int k=0;k<len;k++){
		vertIdx[k]=k;
		for (int i=pres[k];i!=-1;i=edges[i].nextEdge){
			if (edges[i].to==src){
				costs[k]=1;
				break;
			}
		}
	}
	int end=len;
	pCosts=&costs;
	while (end>0){
		std::sort(vertIdx.begin(),vertIdx.begin()+end,MyCompare);
		int curVert=vertIdx[end-1];
		for (int i=pres[curVert];i!=-1;i=edges[i].nextEdge){
			costs[edges[i].to]=std::min<int> (costs[curVert]+1,costs[edges[i].to]);
		}
		end--;
	}

}

int main (){
	fin>>w>>h;
	string line;
	getline(fin,line);
	for (int j=0;j<2*h+1;j++){
		getline(fin,line);
		for (int i=0;i<w*2+1;i++){
			if (i<line.length()){
				orgGraph[j][i]=line[i];
			}
			else{
				orgGraph[j][i]=' ';
			}
		}

	}
	//construct connectivity
	int exits[2];
	int exitCount=0;
	len=h*w;
	pres.resize(len,0);
	for (int y=0;y<h;y++){
		for (int x=0;x<w;x++){
			int index=y*w+x;
			pres[index]=-1;
			if (orgGraph[2*y][2*x+1]==' '){
				if (y-1<0){
					exits[exitCount]=index;
					exitCount++;
				}
				else{				//a edge
					if (pres[index]==-1){
						pres[index]=edges.size();	//first edge for current
					}
					else{
						edges[edges.size()-1].nextEdge=edges.size();
					}
					edges.push_back(Edge(index-w,-1));
				}
			}
			if (orgGraph[2*y+1][2*x+2]==' '){
				if (x+1>=w){
					exits[exitCount]=index;
					exitCount++;
				}
				else{
					if (pres[index]==-1){
						pres[index]=edges.size();
					}
					else{
						edges[edges.size()-1].nextEdge=edges.size();
					}
					edges.push_back(Edge(index+1,-1));
				}
			}
			if (orgGraph[2*y+2][2*x+1]==' '){
				if (y+1>=h){
					exits[exitCount]=index;
					exitCount++;
				}
				else{
					if (pres[index]==-1){
						pres[index]=edges.size();
					}
					else{
						edges[edges.size()-1].nextEdge=edges.size();
					}
					edges.push_back(Edge(index+w,-1));
				}
			}
			if (orgGraph[2*y+1][2*x]==' '){
				if (x-1<0){
					exits[exitCount]=index;
					exitCount++;
				}
				else{
					if (pres[index]==-1){
						pres[index]=edges.size();
					}
					else{
						edges[edges.size()-1].nextEdge=edges.size();
					}
					edges.push_back(Edge(index-1,-1));
				}
			}
		}
	}
	//run dijsktra
	vertIdx.resize(len);
	costs1.resize(len);
	costs2.resize(len);
	CalcCost(exits[0],costs1);
	CalcCost(exits[1],costs2);
	int largest=0;
	for (int i=0;i<len;i++){
		int cost=std::min(costs1[i],costs2[i]);
		largest=std::max(largest,cost);
	}
	fout<<largest+1<<endl;
	return 0;
}
/*
ID: yezhiyo1
PROG: rect1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("rect1.in");
ofstream fout("rect1.out");
int A,B,N;

struct Rect{
	int x0,y0;
	int x1,y1;
	int color;
	Rect(){}
	Rect(int _x0,int _y0,int _x1,int _y1,int _color):x0(_x0),x1(_x1),y0(_y0),y1(_y1),color(_color){}
};
std::vector <Rect> rects;
std::vector <int>  colors;
vector <int> xAxis(4);
vector <int> yAxis(4);


//the fifthTree
struct QNode{
	int  child[5];
	bool leaf;
	int  recIndex;
	QNode(){
		leaf=true;
		for (int i=0;i<5;i++){
			child[i]=-1;
		}
	}
};
std::vector <QNode> qTree;

void Insert(int curNode,const Rect &rect){
	int index=rects.size();
	rects.push_back(rect);
	QNode newNode;
	newNode.recIndex=index;
	qTree.push_back(newNode);
	if (curNode==-1){	//build the root
		
	}
	else{
		if (qTree[curNode].leaf==true){
			qTree[curNode].leaf=false;
			qTree[curNode].child[0]=qTree.size()-1;
		}
		else{
			for (int i=0;i<5;i++){
				if (qTree[curNode].child[i]==-1){
					qTree[curNode].child[i]=qTree.size()-1;
				}
			}
		}
	}
}

bool CheckInter(const Rect &rec1,const Rect &rec2){
	//check inter
	if (rec1.x0>=rec2.x1 ||
		rec1.x1<=rec2.x0 ||
		rec1.y0>=rec2.y1 ||
		rec1.y1<=rec2.y0){
			return false;
	}
	return true;
}

void Divide(const Rect &rect,int node){
	Rect smallRect;
	int curRectIndex=qTree[node].recIndex;
	Rect nodeRect=rects[curRectIndex];
	xAxis[0]=nodeRect.x0;
	xAxis[1]=nodeRect.x1;
	xAxis[2]=rect.x0;
	xAxis[3]=rect.x1;

	yAxis[0]=nodeRect.y0;
	yAxis[1]=nodeRect.y1;
	yAxis[2]=rect.y0;
	yAxis[3]=rect.y1;

	std::sort(xAxis.begin(),xAxis.end());
	std::sort(yAxis.begin(),yAxis.end());
	smallRect.x0=xAxis[1];
	smallRect.x1=xAxis[2];
	smallRect.y0=yAxis[1];
	smallRect.y1=yAxis[2];
	smallRect.color=rect.color;
	Insert(node,smallRect);
	if (nodeRect.x0<smallRect.x0){
		Rect newRect(nodeRect.x0,nodeRect.y0,smallRect.x0,nodeRect.y1,nodeRect.color);
		Insert(node,newRect);
	}
	if (nodeRect.x1>smallRect.x1){
		Rect newRect(smallRect.x1,nodeRect.y0,nodeRect.x1,nodeRect.y1,nodeRect.color);
		Insert(node,newRect);
	}
	if (nodeRect.y0<smallRect.y0){
		Rect newRect(smallRect.x0,nodeRect.y0,smallRect.x1,smallRect.y0,nodeRect.color);
		Insert(node,newRect);
	}
	if (nodeRect.y1>smallRect.y1){
		Rect newRect(smallRect.x0,smallRect.y1,smallRect.x1,nodeRect.y1,nodeRect.color);
		Insert(node,newRect);
	}

}

void QueryTree(const Rect &rect,int root){
	QNode &rootNode=qTree[root];
	if (CheckInter(rect,rects[rootNode.recIndex])){
		if (rootNode.leaf){
			Divide(rect,root);
		}
		else{
			for (int i=0;i<5;i++){
				if (rootNode.child[i]==-1){
					break;
				}
				else{
					QueryTree(rect,rootNode.child[i]);
				}
			}
		}
	}
}

void DrawRect(const Rect &rect){
	QueryTree(rect,0);
}

void CheckAndDivide(const Rect &rect,int r2){
	Rect &curRect=rects[r2];
	if (curRect.color==rect.color){
		return;
	}
	//check inter
	if (curRect.x0>=rect.x1 ||
		curRect.x1<=rect.x0 ||
		curRect.y0>=rect.y1 ||
		curRect.y1<=rect.y0){
		return;
	}
	//
	Rect smallRect;
	xAxis[0]=curRect.x0;
	xAxis[1]=curRect.x1;
	xAxis[2]=rect.x0;
	xAxis[3]=rect.x1;

	yAxis[0]=curRect.y0;
	yAxis[1]=curRect.y1;
	yAxis[2]=rect.y0;
	yAxis[3]=rect.y1;

	std::sort(xAxis.begin(),xAxis.end());
	std::sort(yAxis.begin(),yAxis.end());
	smallRect.x0=xAxis[1];
	smallRect.x1=xAxis[2];
	smallRect.y0=yAxis[1];
	smallRect.y1=yAxis[2];
	smallRect.color=rect.color;
	
	if (rects[r2].x0<smallRect.x0){
		rects.push_back(Rect(rects[r2].x0,rects[r2].y0,smallRect.x0,rects[r2].y1,rects[r2].color));
	}
	if (rects[r2].x1>smallRect.x1){
		rects.push_back(Rect(smallRect.x1,rects[r2].y0,rects[r2].x1,rects[r2].y1,rects[r2].color));
	}
	if (rects[r2].y0<smallRect.y0){
		rects.push_back(Rect(smallRect.x0,rects[r2].y0,smallRect.x1,smallRect.y0,rects[r2].color));
	}
	if (rects[r2].y1>smallRect.y1){
		rects.push_back(Rect(smallRect.x0,smallRect.y1,smallRect.x1,rects[r2].y1,rects[r2].color));
	}

	rects[r2].x0=smallRect.x0;
	rects[r2].x1=smallRect.x1;
	rects[r2].y0=smallRect.y0;
	rects[r2].y1=smallRect.y1;
	rects[r2].color=smallRect.color;
}




int main (){
	fin>>A>>B>>N;
	Rect rootRect(0,0,A,B,1);
	Insert(-1,rootRect);
	colors.resize(2500+1,0);
	for (int i=0;i<N;i++){
		int x0,y0;
		int x1,y1;
		int color;
		fin>>x0>>y0>>x1>>y1>>color;
		Rect rect(x0,y0,x1,y1,color);
		DrawRect(rect);
	}
	for (int i=0;i<rects.size();i++){
		int area=(rects[i].x1-rects[i].x0)*(rects[i].y1-rects[i].y0);
		colors[rects[i].color]+=area;
	}

	for (int i=1;i<colors.size();i++){
		if (colors[i]>0){
			fout<<i<<" "<<colors[i]<<endl;
		}
	}
	return 0;
}
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
	int area;
	bool cut;
	Rect(){
		cut=false;
	}
	Rect(int _x0,int _y0,int _x1,int _y1,int _color):x0(_x0),x1(_x1),y0(_y0),y1(_y1),color(_color){
		area=(x1-x0)*(y1-y0);
		cut=false;
	}
};
std::vector <Rect> rects;
std::vector <int>  colors;

bool CheckInter(const Rect &rec1,const Rect &rec2){
	//check inter
	if (rec1.x0>=rec2.x1){
		return false;
	}
	if (rec1.x1<=rec2.x0){
		return false;
	}
	if (rec1.y0>=rec2.y1){
		return false;
	}
	if (rec1.y1<=rec2.y0){
		return false;
	}
	return true;
}

void Insert(const Rect &rect){
	if (rect.area>0){
		rects.push_back(rect);
	}
}

void InsertRect(int id,const Rect &rect){
	Rect nodeRect=rects[id];
	Rect smallRect(max(rect.x0,nodeRect.x0),
				   max(rect.y0,nodeRect.y0),
				   min(rect.x1,nodeRect.x1),
				   min(rect.y1,nodeRect.y1),
				   rect.color);
	Insert(Rect(nodeRect.x0,nodeRect.y0,smallRect.x0,nodeRect.y1,nodeRect.color));
	Insert(Rect(smallRect.x1,nodeRect.y0,nodeRect.x1,nodeRect.y1,nodeRect.color));
	Insert(Rect(smallRect.x0,nodeRect.y0,smallRect.x1,smallRect.y0,nodeRect.color));
	Insert(Rect(smallRect.x0,smallRect.y1,smallRect.x1,nodeRect.y1,nodeRect.color));
	rects[id].cut=true;
}

void DrawRect(const Rect &rect){
	for (int i=0;i<rects.size();i++){
		if (!rects[i].cut){
			if (CheckInter(rects[i],rect)){
				InsertRect(i,rect);
			}
		}
	}
	rects.push_back(rect);
}


int main (){
	fin>>A>>B>>N;
	colors.resize(2500+1,0);
	Rect rootRect(0,0,A,B,1);
	rects.push_back(rootRect);
	for (int i=0;i<N;i++){
		int x0,y0;
		int x1,y1;
		int color;
		fin>>x0>>y0>>x1>>y1>>color;
		Rect rect(x0,y0,x1,y1,color);
		DrawRect(rect);
	}
	for (int i=0;i<rects.size();i++){
		if (!rects[i].cut){
			colors[rects[i].color]+=rects[i].area;
		}
	}
	for (int i=1;i<(int)colors.size();i++){
		if (colors[i]>0){
			fout<<i<<" "<<colors[i]<<endl;
		}
	}
	return 0;
}
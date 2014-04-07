/*
ID: yezhiyo1
PROG: fence4
LANG: C++
*/
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
#include <memory.h>
using namespace std;
ifstream fin("fence4.in");
ofstream fout("fence4.out");
#define tr(container, it) \
	for (typeof(containter.begin()) it = container.begin(); it != container.end();it++)


int N;

struct CVec2{
	int x,y;
	CVec2 (int _x,int _y):x(_x),y(_y){}
};
std::vector <CVec2> points;


bool CheckIntersect(CVec2 p1,CVec2 p2,CVec2 p3,CVec2 p4){

}

bool Test(int cur){
	typedef std::pair <CVec2,CVec2> scPairv2;
	typedef std::list <scPairv2> scListTri;
	scListTri triList;
	scPairv2 tri(points[cur],points[cur+1]);
	triList.push_back(tri);
	for (int i=0;i<N;i++){
		if (i!=cur){
			int next=(i+1)%N;
			
		}
	}
}


CVec2 obs;
int main (){
	fin>>N;
	points.resize(N);
	fin>>obs.x>>obs.y;
	for (int i=0;i<N;i++){
		fin>>points[i].x>>points[i].y;
		if (i>=2){
			CVec2 p1=points[i-1];
			CVec2 p2=points[i];
			for (int j=0;j<i-1;j++){
				CVec2 p3=points[j];
				CVec2 p4=points[j+1];
				if (CheckIntersect(p1,p2,p3,p4)){
					fout<<"NOFENCE"<<endl;
					return 0;
				}
			}
		}
		if (i==N-1){
			CVec2 p1=points[0];
			CVec2 p2=points[i];
			for (int j=0;j<N-1;j++){
				CVec2 p3=points[j];
				CVec2 p4=points[j+1];
				if (CheckIntersect(p1,p2,p3,p4)){
					fout<<"NOFENCE"<<endl;
					return 0;
				}
			}
		}
	}
	std::vector <bool> canSee;
	canSee.resize(N-1,false);
	int count=0;
	for (int i=0;i<N;i++){
		if (Test(i)){
			canSee[i]=true;
			count++;
		}
	}

	fout<<count<<endl;
	for (int i=0;i<N;i++){
		if (canSee[i]){
			fout<<points[i].x<<" "<<points[i].y<<" "
				<<points[i+1].x<<" "<<points[i+1].y<<endl;
		}
	}

	return 0;
}
/*
ID: yezhiyo1
PROG: fence4
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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
int N;

struct CVec2{
	int x,y;
	CVec2 (int _x,int _y):x(_x),y(_y){}
};
std::vector <CVec2> points;


bool CheckIntersect(CVec2 p1,CVec2 p2,CVec2 p3,CVec2 p4){

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
	}

	for (int i=0;i<N-1;i++){
		CVec2 p1=points[i];
		CVec2 p2=points[i+1];
		int interNum[2]=0;
		bool  canSeeFlag=true;
		for (int j=0;j<N-1;j++){
			if (j==i){
				continue;
			}
			CVec2 p3=points[j];
			CVec2 p4=points[j+1];
			bool t1=CheckIntersect(obs,p1,p3,p4);
			bool t2=CheckIntersect(obs,p2,p3,p4);
			if (t1){
				interNum[0]++;
			}
			if (t2){
				interNum[1]++;
			}
			if (interNum[0] && interNum[1]){
				canSeeFlag=false;
				break;
			}
		}
		if (canSeeFlag){
			fout<<p1.x<<" "<<p1.y<<" "<<p2.x<<" "<<p2.y<<endl;
		}
	}

	return 0;
}
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
#include <cmath>
#include <memory.h>
using namespace std;
ifstream fin("fence4.in");
ofstream fout("fence4.out");
#ifdef __GNUC__
#define tr(container, it) \
	for (typeof(container.begin()) it = container.begin(); it != container.end();it++)

#define trCheck(container, it) \
	for (typeof(container.begin()) it = container.begin(); it != container.end();)

#else
#ifdef _MSC_VER
#define tr(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();it++)
#define trCheck(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();)

#endif
#endif

typedef std::pair<int,int> scPair2i;

int N;

double eps=1e-5;

struct CVec2{
	double x,y;
	CVec2 (double _x,double _y):x(_x),y(_y){}
	CVec2(){}
	~CVec2(){}
};
CVec2 obs;
std::vector <CVec2> points;

CVec2 operator -(const CVec2 &v1,const CVec2 &v2){
	return CVec2(v1.x-v2.x,v1.y-v2.y);
}
CVec2 operator +(const CVec2 &v1,const CVec2 &v2){
	return CVec2(v1.x+v2.x,v1.y+v2.y);
}
CVec2 operator *(const CVec2 &v1,double a){
	return CVec2(v1.x*a,v1.y*a);
}

bool operator ==(const CVec2 &v1,const CVec2 &v2){
	CVec2 v3=v1-v2;
	if (fabs(v3.x)<eps && fabs(v3.y)<eps){
		return true;
	}
	return false;
}



typedef std::pair <CVec2,CVec2> scPairv2;
typedef std::list <scPairv2> scListTri;
double GetCross(CVec2 A,CVec2 B,CVec2 C,CVec2 D){
	CVec2 AB=B-A;
	CVec2 CD=D-C;
	return AB.x*CD.y-AB.y*CD.x;
}
bool Inside(CVec2 p,CVec2 A,CVec2 B,CVec2 C){
	double s1=GetCross(p,A,p,B);
	double s2=GetCross(p,A,p,C);
	double s3=GetCross(p,B,p,C);
	double sumS=fabs(s1)+fabs(s2)+fabs(s3);
	double s=fabs(GetCross(A,B,A,C));
	if (fabs(sumS-s)<=eps){
		return true;
	}
	return false;
}

bool CheckIntersect(CVec2 O,CVec2 X,CVec2 A,CVec2 B){
	double dx1=X.x-O.x;
	double dy1=X.y-O.y;
	double dx2=B.x-A.x;
	double dy2=B.y-A.y;
	double x1=O.x;
	double x2=A.x;
	double y1=O.y;
	double y2=A.y;
	double i=dy2*(x2-x1)-dx2*(y2-y1);
	i/=dy2*dx1-dx2*dy1;
	double j=dy1*(x1-x2)-dx1*(y1-y2);
	j/=dy1*dx2-dx1*dy2;
	
	if (i>eps && i<(1.0-eps) &&
		j>eps && j<(1.0-eps)){
			return true;
	}
	return false;
}

CVec2 GetInter(CVec2 O,CVec2 X,CVec2 A,CVec2 B){
	double dx1=X.x-O.x;
	double dy1=X.y-O.y;
	double dx2=B.x-A.x;
	double dy2=B.y-A.y;
	double x1=O.x;
	double x2=A.x;
	double y1=O.y;
	double y2=A.y;
	double i=dy2*(x2-x1)-dx2*(y2-y1);
	i/=dy2*dx1-dx2*dy1;
	double j=dy1*(x1-x2)-dx1*(y1-y2);
	j/=dy1*dx2-dx1*dy2;
	return O+(X-O)*i;
}




void InterSect(scListTri &triList,CVec2 p1,CVec2 p2){
	scListTri newTriList;
	for (scListTri::iterator it=triList.begin();it!=triList.end();){
		CVec2 A=it->first;
		CVec2 B=it->second;
		CVec2 O=obs;
		bool a=Inside(p1,A,B,O);
		bool b=Inside(p2,A,B,O);
		bool iterFlag=true;
		if (!a && !b){
			if (CheckIntersect(O,A,p1,p2) && CheckIntersect(O,B,p1,p2)){
				triList.erase(it++);
				iterFlag=false;
			}
		}
		else if ((!a&&b)||(a&&!b)){
			CVec2 newP1,newP2;
			if (b){
				newP1=p2;
				newP2=p1;
			}
			else{
				newP1=p1;
				newP2=p2;
			}	//newP1 inside 
			CVec2 C=GetInter(O,newP1,A,B);
			if (CheckIntersect(O,A,p1,p2)){
				it->first=C;
			}
			else if (CheckIntersect(O,B,p1,p2)){
				it->second=C;
			}
		}
		else if (a&&b){
			CVec2 C=GetInter(O,p1,A,B);
			CVec2 D=GetInter(O,p2,A,B);
			double soac=GetCross(O,A,O,C);
			double soad=GetCross(O,A,O,D);
			double soab=GetCross(O,A,A,B);
			if (fabs(soad)<fabs(soac)){
				std::swap (C,D);
				std::swap (soac,soad);
			}
			it->second=C;
			double delta=fabs(soad)-fabs(soab);
			if (fabs(delta)>eps){
				newTriList.push_back(scPairv2(D,B));
			}
		}
		else{
			cout<<"error!\n";
		}
		if (iterFlag){
			it++;
		}
	}
	tr(newTriList,iter){
		triList.push_back(*iter);
	}
}

bool Test(int cur){
	scListTri triList;
	scPairv2 tri(points[cur],points[(cur+1)%N]);

	double sOAB=GetCross(obs,tri.first,obs,tri.second);
	sOAB=fabs(sOAB);
	if (sOAB<=eps){
		return false;
	}


	triList.push_back(tri);
	for (int i=0;i<N;i++){
		if (i!=cur){
			int next=(i+1)%N;
			CVec2 &p1=points[i];
			CVec2 &p2=points[next];

			InterSect(triList,p1,p2);
			if (triList.empty()){
				return false;
			}
		}
	}


	trCheck(triList,iter){
		CVec2 A=iter->first;
		CVec2 B=iter->second;
		bool iterFlag=true;
		if (A==B){
			triList.erase(iter++);
			iterFlag=false;
		}
		if (iterFlag){
			iter++;
		}
	}

	if (triList.empty()){
		return false;
	}
	return true;
}



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
	
	std::set <scPair2i> seePoints;
	int count=0;
	for (int i=0;i<N;i++){
		if (i==19){
			int a=1;
		}
		if (Test(i)){
			int a=(i+1)%N,b=i;
			if (a<b){
				std::swap (a,b);
			}
			seePoints.insert(scPair2i(a,b));
			count++;
		}
	}

	fout<<count<<endl;
	tr(seePoints,iter){
		CVec2 p1=points[iter->second];
		CVec2 p2=points[iter->first];
		fout<<p1.x<<" "<<p1.y<<" "
			<<p2.x<<" "<<p2.y<<endl;
	}
	return 0;
}
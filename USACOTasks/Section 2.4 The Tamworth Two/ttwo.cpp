/*
ID: yezhiyo1
LANG: C++
TASK: ttwo
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
char c[10][10];
struct Node{
	int x,y;
	int dir;
	Node (int _x,int _y,int _dir):x(_x),y(_y),dir(_dir){}
};
vector <Node> path1;
int			  circleStart1;
vector <Node> path2;
int			  circleStart2;
typedef vector <Node> scVec;

void BuildPath(int startX,int startY,scVec &path,int &circle){
	int dir=0;
	int xDirMap[4]={0,1,0,-1};
	int ydirMap[4]={-1,0,1,0};
	Node temp(startX,startY,dir);
	path.push_back(temp);
	int x=startX,y=startY;
	while (true){
		int tempX,tempY;
		tempX=x+xDirMap[dir];
		tempY=y+ydirMap[dir];
		if (tempX<0 || tempX>=10 ||
			tempY<0 || tempY>=10){	//out bound
				dir++;
		}
		else{
			if (c[tempY][tempX]=='*'){
				dir++;
			}
			else{
				x=tempX;
				y=tempY;
			}
		}
		dir%=4;
		bool isCircle=false;
		for (int i=0;i<path.size();i++){
			if (path[i].x==x && path[i].y==y &&	path[i].dir==dir){
				isCircle=true;
				circle=i;
				break;
			}
		}
		if (isCircle){
			break;
		}
		path.push_back(Node(x,y,dir));
	}
}

int GCD(int a,int b){
	if (a<b){
		return GCD(b,a);
	}
	else if (b==0){
		return a;
	}
	else{
		return GCD(b,a%b);
	}
}

int CalTime(){
	int n1=path1.size();
	int n2=path2.size();
	int c1=n1-circleStart1;
	int c2=n2-circleStart2;
	int gcd=GCD(c1,c2);
	int lmr=c1*c2/gcd;
	int tot=lmr+std::max<int>(circleStart1,circleStart2);
	for (int i=0;i<tot;i++){
		int i1=i<circleStart1?i:((i-circleStart1)%c1+circleStart1);
		int i2=i<circleStart2?i:((i-circleStart2)%c2+circleStart2);
		if (path1[i1].x==path2[i2].x &&
			path1[i1].y==path2[i2].y){
			return i;
		}
	}
	return 0;
}

int main (){
	int fx,fy;
	int cx,cy;
	for (int i=0;i<10;i++){
		for (int j=0;j<10;j++){
			fin>>c[i][j];
			if (c[i][j]=='F'){
				fx=j;
			    fy=i;
				c[i][j]='.';
			}
			else if (c[i][j]=='C'){
				cx=j;
				cy=i;
				c[i][j]='.';
			}
		}
	}
	BuildPath(fx,fy,path1,circleStart1);
	BuildPath(cx,cy,path2,circleStart2);
	fout<<CalTime()<<endl;
	return 0;
}

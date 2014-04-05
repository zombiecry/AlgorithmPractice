/*
ID: yezhiyo1
PROG: range
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
ifstream fin("range.in");
ofstream fout("range.out");

const int MAX_N = 250;
bool c[MAX_N][MAX_N][2];
int  m[MAX_N];
int N;


int main (){
	fin>>N;
	char tmp;
	for (int j=0;j<N;j++){
		for (int i=0;i<N;i++){
			fin>>tmp;
			c[j][i][0]=tmp-'0';
			c[j][i][1]=0;
		}
		m[j]=0;
	}


	for (int j=2;j<=N;j++){
		for (int x=0;x<=N-j;x++) for (int y=0;y<=N-j;y++){
			c[y][x][1]=c[y][x][0] && c[y][x+1][0] && c[y+1][x][0] &&c[y+1][x+1][0];
		}
		for (int x=0;x<N;x++) for (int y=0;y<N;y++){
			c[y][x][0]=c[y][x][1];
			if (c[y][x][0]){
				m[j]++;
			}
			c[y][x][1]=0;
		}
	}

	for (int i=2;i<=N;i++){
		if (m[i]){
			fout<<i<<" "<<m[i]<<endl;
		}
	}

	return 0;
}
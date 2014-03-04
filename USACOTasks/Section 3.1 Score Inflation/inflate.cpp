/*
ID: yezhiyo1
PROG: inflate
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("inflate.in");
ofstream fout("inflate.out");
int m,n;
std::vector <int> times;
std::vector <int> points;
std::vector <int> c;	//dup-item knapsack

int main (){
	fin>>m>>n;
	times.resize(n);
	points.resize(n);
	c.resize(m+1);
	for (int i=0;i<n;i++){
		fin>>points[i]>>times[i];
	}
	c[0]=0;
	for (int i=1;i<=m;i++){
		c[i]=0;
		for (int j=0;j<n;j++){
			if (i-times[j]>=0){
				c[i]=std::max(c[i],c[i-times[j]]+points[j]);
			}
		}
	}
	fout<<c[m]<<endl;
	return 0;
}
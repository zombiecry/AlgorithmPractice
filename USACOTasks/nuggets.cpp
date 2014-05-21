/*
ID: yezhiyo1
PROG: nuggets
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;
ifstream fin("nuggets.in");
ofstream fout("nuggets.out");
int n;
const long long int M=2000000000;
vector <int> a;

deque <bool> c;
int main (){
	fin>>n;
	a.resize(n);
	for (int i=0;i<n;i++){
		fin>>a[i];
	}
	sort(a.begin(),a.end());
	int b=0;
	int y=-1;
	c.resize(a[n-1]+1,false);
	c[0]=true;
	for (int i=1;i<c.size();i++){
		c[i]=false;
		for (int j=0;j<n;j++){
			if (i-a[j]>=0){
				if (c[i-a[j]]){
					c[i]=true;
					break;
				}
			}
		}
		if (!c[i]){
			y=i;
		}
	}
	int count=0;
	for (int i=a[n-1]+1;i<=M;i++){
		bool x=false;
		for (int j=0;j<n;j++){
			if (c[i-a[j]-b]){
				x=true;
				break;
			}
		}
		if (!x){
			y=i;
			count=0;
		}
		else{
			count++;
			if (count>a[n-1]+2){
				break;
			}
		}
		c.pop_front();
		c.push_back(x);
		b++;
	}
	if (y==-1){
		fout<<0<<endl;
		return 0;
	}
	fout<<y<<endl;
	return 0;
}
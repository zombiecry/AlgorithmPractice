#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include<queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
ifstream fin("B-large.in");
ofstream fout("b1.out");
int T;
vector <int> s;
double Solve(int B,int L,int N){
	vector <vector <double>> c[2];
	for (int i=0;i<2;i++){
		c[i].resize(L);
		for (int j=0;j<L;j++){
			c[i][j].resize(j+1,0);
		}
	}
	c[0][0][0]=3*B*250;
	for (int i=0;i<L-1;i++){
		int cur=i%2;
		int next=(i+1)%2;
		for (int j=0;j<i+1+1;j++) for (int k=0;k<j+1;k++){
			c[next][j][k]=0;
		}
		for (int j=0;j<i+1;j++) for (int k=0;k<j+1;k++){
			if (c[cur][j][k]>250){
				double left=(c[cur][j][k]-250)/3;
				c[next][j][k]+=left;
				c[next][j+1][k]+=left;
				c[next][j+1][k+1]+=left;
			}
		}
	}
	int cur=(L-1)%2;
	int count=0;
	for (int i=0;i<L;i++) for (int j=0;j<i+1;j++){
		if (count==N-1){
			return c[cur][i][j]>250.0?250.0:c[cur][i][j];
		}
		count++;
	}
	return 0;
}
int main (){
	s.resize(400,0);
	s[0]=1;
	for (int i=1;i<400;i++){
		s[i]=s[i-1]+(i+1);
	}
	fin>>T;
	for (int i=0;i<T;i++){
		int B,L,N;
		fin>>B>>L>>N;
		if (i!=7-1){
			//continue;
		}
		setprecision(9);
		fout<<"Case #"<<i+1<<setiosflags(ios::fixed)<<setprecision(7)<<": "<<Solve(B,L,N)<<endl;
	}
	return 0;
}
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
#if 1
ifstream fin("fetch.in");
ofstream fout("fetch.out");
#define cin fin
#define cout fout
#endif
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
typedef pair<int,int> scPair2i;


int m,n;
int cn;
const int MAX_MN = 100;
const int INF = 0xfffffff;
int   mat[MAX_MN][MAX_MN];
int   e[MAX_MN+2][MAX_MN+2];	//cost
int   c[MAX_MN+2][MAX_MN+2];	//capacity
int   r[MAX_MN+2][MAX_MN+2];	//residel
int   f[MAX_MN+2][MAX_MN+2];	//flow
int   s,t;

void MCMP(){

}

int CalcSum(){
	int vm=m+n+2;
	s=m+n;
	t=m+n+1;
	for (int i=0;i<vm;i++){
		for (int j=0;j<vm;j++){
			e[i][j]=INF;
			c[i][j]=0;
			f[i][j]=0;
		}
	}
	for (int j=0;j<n;j++){
		for (int i=0;i<m;i++){
			e[j][i+n]=mat[i][j];
			c[j][i+n]=1;
		}
	}
	for (int i=0;i<n;i++){
		e[s][i]=0;
		c[s][i]=1;
	}
	for (int i=0;i<m;i++){
		e[i+n][t]=0;
		c[i+n][t]=1;
	}
	MCMP();
	vector <bool> covered(m+n,false);
	int sum=0;
	for (int j=0;j<n;j++){
		for (int i=0;i<m;i++){
			if (f[j][i+n]){		//have flow
				covered[j]=true;
				covered[i+n]=true;
				sum+=e[j][i+n];
			}
		}
	}
	
	for (int i=0;i<m+n;i++){
		if (!covered[i]){
			int minWeight=INF;
			for (int j=0;j<m+n;j++){
				minWeight=min(minWeight,e[i][j]);
				minWeight=min(minWeight,e[j][i]);
			}
			sum+=minWeight;
		}
	}
	
	return sum;
}


int main (){
	cin>>cn;
	for (int k=0;k<cn;k++){
		cin>>m>>n;
		for (int i=0;i<m;i++){
			for (int j=0;j<n;j++){
				cin>>mat[i][j];
			}
		}
		cout<<"Case "<<k+1<<": "<<CalcSum()<<endl;
	}
	return 0;
}
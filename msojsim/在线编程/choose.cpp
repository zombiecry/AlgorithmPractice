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
#if 0
ifstream fin("choose.in");
ofstream fout("choose.out");
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

int cn;
int n;
long unsigned int res;
const long unsigned int restrict=1e9+7;
void Calc(){
	res=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++){
				if (i==j || i==k || j==k){
					if (!(i==j && j==k)){
						continue;
					}
				}
				res+=(n+1-i)*(n+1-j)*(n+1-k);
				res%=restrict;
			}
		}
	}
}


int main (){
	cin>>cn;
	for (int i=0;i<cn;i++){
		cin>>n;
		Calc();
		cout<<"Case "<<i+1<<": "<<res<<endl;
	}
	
	return 0;
}
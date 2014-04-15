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
ifstream fin("string.in");
ofstream fout("string.out");
#define cin fin
#define cout fout
#endif
#define tr(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();it++)
#define trCheck(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();)


#define MAX_N 100
int cn;
int MyMin(int a,int b,int c) {   
	int t = a < b ? a : b;   
	return t < c ? t : c;   
}   
int EditDistance(string a,string b){
	int len1=a.length()-1;
	int len2=b.length()-1;
	int d[MAX_N][MAX_N];   
	int i,j;   
	for(i = 0;i <= len1;i++)   
		d[i][0] = i;   
	for(j = 0;j <= len2;j++)   
		d[0][j] = j;   
	for(i = 1;i <= len1;i++)   
		for(j = 1;j <= len2;j++) {   
			int cost = a[i] == b[j] ? 0 : 1;   
			int deletion = d[i-1][j] + 1;   
			int insertion = d[i][j-1] + 1;   
			int substitution = d[i-1][j-1] + cost;   
			d[i][j] = MyMin(deletion,insertion,substitution);   
		}   
		return d[len1][len2];   
}



int main (){
	string line;
	map <string,int> fMap;
	while (getline(cin,line)){
		if (line.length()){
			bool findFlag=false;
			for (map<string,int>::iterator it = fMap.begin(); it != fMap.end();){
				int dist=EditDistance(it->first,line);
				if (dist<=5){
					fMap[it->first]++;
					findFlag=true;
					break;
				}
			}
			if (!findFlag){
				fMap[line]=1;
			}
		}
	}
	int maxNum=0;
	for (map<string,int>::iterator it = fMap.begin(); it != fMap.end();){

		maxNum=max(maxNum,it->second);
	}

	cout<<maxNum<<endl;
	return 0;
}
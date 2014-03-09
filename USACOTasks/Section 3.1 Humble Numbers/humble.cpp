/*
ID: yezhiyo1
PROG: humble
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("humble.in");
ofstream fout("humble.out");
int k,n;
std::vector <int> primes;
std::vector <long> lastIndex;
std::vector <long> c;

int main (){
	fin>>k>>n;
	primes.resize(k);
	lastIndex.resize(k,0);
	for (int i=0;i<k;i++){
		fin>>primes[i];
	}
	c.push_back(1);
	while (c.size()<n+1){
		long minVal=0x7fffffff;
		int  minIndex=-1;
		for (int i=0;i<k;i++){
			long newVal=c[lastIndex[i]]*primes[i];
			if (newVal<minVal && newVal>c[c.size()-1]){
				minVal=newVal;
				minIndex=i;
			}
		}
		for (int i=0;i<k;i++){		
			if (c[lastIndex[i]]*primes[i] == minVal){
				lastIndex[i]++;
			}
		}
		c.push_back(minVal);
	}
	fout<<c[n]<<endl;
	return 0;
}
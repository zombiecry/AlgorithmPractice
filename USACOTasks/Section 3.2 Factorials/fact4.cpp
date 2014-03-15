/*
ID: yezhiyo1
PROG: fact4
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("fact4.in");
ofstream fout("fact4.out");
int N;
int main (){
	fin>>N;
	int num5=0;
	int divFact=5;
	while (N>=divFact){
		num5+=N/divFact;
		divFact*=5;
	}

	int cur=1;
	int a2=num5;
	int a5=num5;
	for (int i=1;i<=N;i++){
		int x=i;
		while (a2 && !(x%2)){
			x=x/2;
			a2--;
		}
		while (a5 && !(x%5)){
			x=x/5;
			a5--;
		}
		cur=(cur*x)%10;
	}
	fout<<cur<<endl;

	return 0;
}
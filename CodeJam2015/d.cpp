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
ifstream fin("D-large.in");
ofstream fout("d1.out");
int T;

bool Check(string &s){
	int l=0;
	for (int i=0;i<s.length();i++){
		if (s[i]=='('){l++;}
		else {l--;}
		if (l<0){return false;}
	}
	return true;
}


string Solve(int n,int k){
	string s;
	s.resize(2*n);
	for (int i=0;i<n;i++){
		s[i]='(';
		s[i+n]=')';
	}
	int r=0;
	do{
		if (Check(s)){
			if (r==k-1){
				return s;
			}
			r++;
		}

	}while(next_permutation(s.begin(),s.end()));
	return "Doesn't Exist!";
}

int main (){
	fin>>T;
	for (int i=0;i<T;i++){
		int n,k;
		fin>>n>>k;
		if (i!=2-1){
			//continue;
		}
		fout<<"Case #"<<i+1<<": "<<Solve(n,k)<<endl;
	}
	return 0;
}
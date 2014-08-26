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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;
string fname="A-large-practice";
ifstream fin(fname+".in");
ofstream fout(fname+".out");
int T;
int N;
int s[]={0x7e,0x30,0x6d,0x79,0x33,0x5b,0x5f,0x70,0x7f,0x7b};
vector <vector <int>> B;
vector <int> A;

int Word2Num(string &word){
	int res=0;
	for (int i=0;i<word.length();i++){
		int index=word.length()-1-i;
		if (word[i]=='1'){
			res |= 1 <<index;
		}
	}
	return res;
}

string Num2Word(int num){
	if (num==-1){
		return "ERROR!";
	}
	string res;
	res.resize(7);
	for (int i=0;i<7;i++){
		int index=6-i;
		if ((num >> i) &1){
			res[index]='1';
		}
		else{
			res[index]='0';
		}
	}
	return res;
}

void Cand(int num,vector <int> &bs){
	for (int i=0;i<10;i++){
		if ((num & s[i]) == num){
			bs.push_back(i);
		}
	}
}
int NextNum(int num){
	int res=num-1;
	if (res< 0){
		res=9;
	}
	return res;
}
int Solve(){
	set <int> resSet;
	for (int i=0;i<B[0].size();i++){
		bool okFlag = true;
		int down    = 0;
		int up		= 0;
		int start   =B[0][i];
		int curNum  =start;
		for (int j=0;j<N;j++){			//calc down
			int a = A[j];
			int b=  s[curNum];
			down |= a^b;
			up   |= a;
			curNum=NextNum(curNum);
		}
		curNum=start;
		for (int j=0;j<N;j++){
			int a = A[j];
			int b=  s[curNum];
			if (find(B[j].begin(),B[j].end(),curNum)==B[j].end()){
				okFlag=false;
				break;
			}
			if (a & down){
				okFlag=false;
				break;
			}
			curNum=NextNum(curNum);
		}
		if (okFlag){
			int lit =s[curNum] & (~down);
			int left= lit & (~up);
			if (left & 0x7f){		//undetermined existed
				return -1;
			}
			else{
				resSet.insert(lit);
				if (resSet.size()>1){
					return -1;
				}
			}
		}
	}
	return *resSet.begin();
}

int main (){
	fin>>T;
	for (int i=0;i<T;i++){
		fin>>N;
		A.clear();
		B.clear();
		A.swap(vector <int>());
		B.swap(vector <vector <int> >());
		A.resize(N);
		B.resize(N);
	
		for (int j=0;j<N;j++){
			string word;
			fin>>word;
			A[j]=Word2Num(word);
			Cand(A[j],B[j]);
		}
		fout<<"Case #"<<i+1<<": "<<Num2Word(Solve())<<endl;
	}
	return 0;
}
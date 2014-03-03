/*
ID: yezhiyo1
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;
char mStr[1000];
bool mFlags[1000];

bool checkRound(unsigned long m){
	sprintf(mStr,"%lu",m);
	int length=strlen(mStr);
	for (int i=0;i<length;i++){
		if (mStr[i]=='0'){
			return false;
		}
		for (int j=i+1;j<length;j++){
			if (mStr[i]==mStr[j]){
				return false;
			}
		}
	}
	memset(mFlags,false,length*sizeof(bool));
	int count=0;
	int ptr=0;
	while (count<length){
		int dig=mStr[ptr]-'0';
		ptr+=dig;
		ptr%=length;
		if (mFlags[ptr]==false){
			mFlags[ptr]=true;
			count++;
		}
		else {
			return false;
		}
	}
	if (ptr==0){
		return true;
	}
	return false;
}
int main(){
	ifstream fin("runround.in");
	ofstream fout("runround.out");
	unsigned long m;
	fin>>m;
	for (unsigned long i=m+1;;i++){
		if (checkRound(i)){
			fout<<i<<endl;
			break;
		}
	}
	
	
	return 0;
}
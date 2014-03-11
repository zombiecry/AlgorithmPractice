/*
ID: yezhiyo1
PROG: rect1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("contact.in");
ofstream fout("contact.out");
int A,B,N;
std::map <string,int> patternMap;
std::vector <string> sortArr;
int sortLen=0;

bool MyCompare(const string &str1,const string &str2){
	return patternMap[str1]>patternMap[str2];
}

void OnChanged(string str){
	if (sortLen<N){
		sortArr[sortLen]=str;
		sortLen++;
		std::sort(sortArr.begin(),sortArr.end(),MyCompare);
		return;
	}
	if (patternMap[str]>=patternMap[sortArr[sortLen-1]]){
		bool insertNew=false;
		int i=sortLen-1;
		for (;i>=0;i--){
			if (patternMap[str]==patternMap[sortArr[i]]){
				break;
			}
			else if (patternMap[str]<patternMap[sortArr[i]]){
				insertNew=true;
				break;
			}
			sortArr[i+1]=sortArr[i];
		}
		sortArr[i+1]=str;
		if (!insertNew){
			sortLen++;
		}
	}
}

int main (){
	fin>>A>>B>>N;
	string totStr;
	fin>>totStr;
	for (int i=0;i<totStr.length();i++){
		for (int j=A;j<=B;j++){
			if (i+j<totStr.length()){
				string curTemp=totStr.substr(i,j);
				if (patternMap.count(curTemp)){
					patternMap[curTemp]++;
				}
				else{
					patternMap[curTemp]=1;
				}
				OnChanged(curTemp);
			}
		}
	}
	int cur=0;
	
	for (int i=0;i<N;i++){
		fout<<patternMap[sortArr[cur]]<<endl;
		int currentNum=patternMap[sortArr[cur]];
		while (patternMap[sortArr[cur]]==currentNum){
			fout<<sortArr[cur]<<" ";
			cur++;
			if (cur>sortLen-1){
				break;
			}
		}
	}

	
	return 0;
}
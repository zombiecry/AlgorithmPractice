/*
ID: yezhiyo1
PROG: concom
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

ifstream fin("concom.in");
ofstream fout("concom.out");
int n;
int c[100][100];
int priVal[100];
std::vector <int> primVec(100);

bool lessComp(const int &n1,const int &n2){
	return priVal[primVec[n1]]<priVal[primVec[n2]];
}

void InitQue(int com){
	for (int i=0;i<100;i++){
		primVec[i]=i;
		priVal[i]=c[com][i];
	}
}

void MySort(int queLen){
	for (int i=0;i<queLen;i++){
		for (int j=queLen-1;j>i;j--){
			
			if (priVal[primVec[j]]<priVal[primVec[j-1]]){
				std::swap (primVec[j],primVec[j-1]);
			}
			
		}
	}
	
}

int main (){
	fin>>n;
	for (int i=0;i<100;i++){
		memset(c[i],0,100*sizeof(int));
	}
	for (int i=0;i<n;i++){
		int a,b,per;
		fin>>a>>b>>per;
		c[a-1][b-1]=per;
	}
	primVec.resize(100);
	for (int i=0;i<100;i++){
		InitQue(i);
		int queLen=100;
		while (queLen>0){
			sort(primVec.begin(),primVec.begin()+queLen,lessComp);
			//MySort(queLen);
			if (priVal[primVec[queLen-1]]>50){	//add new nodes
				c[i][primVec[queLen-1]]=51;		//add connect
				for (int j=0;j<100;j++){
					priVal[j]+=c[primVec[queLen-1]][j];
				}
				queLen--;
			}
			else{
				break;
			}
		}
	}
	for (int i=0;i<100;i++){
		for (int j=0;j<100;j++){
			if (c[i][j]>50 && i!=j){
				fout<<i+1<<" "<<j+1<<endl;
			}
		}
	}

	return 0;
}
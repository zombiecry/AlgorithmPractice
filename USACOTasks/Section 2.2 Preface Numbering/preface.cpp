/*
ID: yezhiyo1
PROG: preface
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;

char cSet[]={'I','V','X','L','C','D','M'};
int nSet[]={0,0,0,0,0,0,0};
int placeMap[]={0,2,4,6};
int highestNumber=0;
void CountNumber(int n){
	char chs[5]={'0'};
	sprintf(chs,"%d",n);
	int length=strlen(chs);
	for (int i=0;i<length;i++){
		int dig=chs[i]-'0';
		int place=placeMap[length-i-1];
		if (dig>0){
			if (dig<4){
				nSet[place]+=dig;
			}
			else if (dig==4){
				nSet[place]+=1;
				nSet[place+1]+=1;
			}
			else if (dig==5){
				nSet[place+1]+=1;
			}
			else if (dig<9){
				nSet[place+1]+=1;
				nSet[place]+=dig-5;
			}
			else if (dig==9){
				nSet[place+2]+=1;
				nSet[place]+=1;
			}
		}
	}
}


int main(){
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	int n;
	fin>>n;
	
	
	for (int i=1;i<=n;i++){
		CountNumber(i);
	}
	
	for (int i=6;i>=0;i--){
		if (nSet[i]>0){
			highestNumber=i+1;
			break;
		}
	}
	for (int i=0;i<highestNumber;i++){
		fout<<cSet[i]<<" ";
		fout<<nSet[i]<<"\n";
	}
	
	fin.close();
	fout.close();
	
	return 0;
}
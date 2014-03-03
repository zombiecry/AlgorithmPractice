/*
ID: yezhiyo1
PROG: zerosum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;
int n;
int c[9];
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

int applyOp(int src1,int src2,int opType){
	if (opType==1){
		return src1+src2;
	}
	else if (opType==2){
		return src1-src2;
	}
}

void checkOk(){
	int sum=0;
	int curOp=-1;
	int conCount=0;
	c[n-1]=1;
	for (int i=0;i<n;i++){
		if (c[i]==0){
			conCount++;
		}
		else{
			int curNumber=0;
			if (conCount>0){
				for (int j=i-conCount;j<=i;j++){
					curNumber*=10;
					curNumber+=(j+1);
				}
				conCount=0;
			}
			else{
				curNumber=i+1;
			}
			if (curOp==-1){	//the first num
				sum+=curNumber;
			}
			else{			//do the op for sum and curNumber
				sum=applyOp(sum,curNumber,curOp);
			}
			curOp=c[i];
		}
	}
	char chMap[]={' ','+','-'};
	if (sum==0){
		for (int i=0;i<n-1;i++){
			fout<<i+1<<chMap[c[i]];
		}
		fout<<n;
		fout<<"\n";
	}

}
int main(){
	fin>>n;
	int trace=0;
	memset (c,-1,(n-1)*sizeof(int));
	while (trace>=0){
		c[trace]++;
		if (c[trace]<3){
			if (trace<n-2){
				trace++;
			}
			else{
				checkOk();
			}
		}
		else{	//backtrack
			c[trace]=-1;
			trace--;
		}
	}
	return 0;
}
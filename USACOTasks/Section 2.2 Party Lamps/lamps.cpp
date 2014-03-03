/*
ID: yezhiyo1
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <memory.h>
using namespace std;
int n;
int cTotal;
bool onLamp[100];
bool offLamp[100];
int c[5];
int okLampIndex[16];

void applyChange(bool *dst,const bool *src,int level,int type){
	memcpy(dst,src,n*sizeof(bool));
	if (level==1 && type==1){
		for (int i=0;i<n;i++){
			dst[i]=!src[i];
		}
	}
	else if (level==2 && type==1){
		for (int i=0;i<n;i+=2){
			dst[i]=!src[i];
		}
	}
	else if (level==3 && type==1){
		for (int i=1;i<n;i+=2){
			dst[i]=!src[i];
		}
	}
	else if (level==4 && type==1){
		for (int i=0;i<n;i+=3){
			dst[i]=!src[i];
		}
	}
}
bool checkOk(bool *src){
	int x=0;
	for (int i=1;i<5;i++){
		if (c[i]==1){
			x++;
		}
	}
	if (cTotal-x>=0){
		if ((cTotal-x)%2!=0){
			return false;
		}
	}
	else{
		return false;
	}
	for (int i=0;i<n;i++){
		if (onLamp[i]){
			if (src[i]!=true){
				return false;
			}
		}
		if (offLamp[i]){
			if (src[i]!=false){
				return false;
			}
		}
	}
	return true;
}
int main (){
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");
	fin>>n;
	fin>>cTotal;
	int temp;
	fin>>temp;
	memset(onLamp,false,n*sizeof(bool));
	memset(offLamp,false,n*sizeof(bool));
	while (temp!=-1){
		onLamp[temp-1]=true;
		fin>>temp;
	}

	fin>>temp;
	while (temp!=-1){
		offLamp[temp-1]=true;
		fin>>temp;
	}
	bool okLamp[16][100];
	int  okCount=0;
	bool lampHis[5][100];
	memset(lampHis[0],true,n*sizeof(bool));
	int trace=1;
	memset(c,-1,5*sizeof(int));
	while (trace>0){
		c[trace]++;
		if (c[trace]<2){
			applyChange(lampHis[trace],lampHis[trace-1],trace,c[trace]);
			if (trace==4){
				if (checkOk(lampHis[trace])){		//there exist redundant.
					bool redundant=false;
					int  index=0;
					for (int i=0;i<okCount;i++){
						bool diff=false;
						bool bigger=false;
						for (int j=0;j<n;j++){
							if (lampHis[trace][j]!=okLamp[i][j]){
								if (lampHis[trace][j]==1){       //big
									bigger=true;
								}
								diff=true;
								break;
							}
						}
						if (!diff){
							redundant=true;
							break;
						}
						if (bigger){
							index++;
						}
					}
					if (!redundant){
						memcpy(okLamp[okCount],lampHis[trace],n*sizeof(bool));
						okCount++;
						for (int i=okCount;i>index;i--){
							okLampIndex[i]=okLampIndex[i-1];
						}
						okLampIndex[index]=okCount-1;
					}
				}
			}
			else{		//next level
				trace++;
			}
		}
		else{	//backtrack
			c[trace]=-1;
			trace--;
		}
	}
	
	if (okCount==0){
		fout<<"IMPOSSIBLE"<<endl;
	}
	for (int i=0;i<okCount;i++){
		for (int j=0;j<n;j++){
			if (okLamp[okLampIndex[i]][j]){
				fout<<"1";
			}
			else{
				fout<<"0";
			}
		}
		fout<<endl;
	}
	return 0;
}
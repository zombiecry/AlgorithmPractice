/*
ID: yezhiyo1
LANG: C++
TASK: fracdec
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
string n;
int d;
std::vector <int> ps;
std::vector <int> resVec;


#define HASH_CAP 100000
struct HNode{
	int val;
	int index;
	int nextNode;
	HNode(int _val,int _index,int _nextNode):val(_val),index(_index),nextNode(_nextNode){}
};
std::vector <HNode> hashNodes;
std::vector <int>   hashPres;

int Exist(int val){
	int key=val%HASH_CAP;
	bool findFlag=false;
	for (int i=hashPres[key];i!=-1;i=hashNodes[i].nextNode){
		if (hashNodes[i].val==val){
			return hashNodes[i].index;
		}
	}
	return -1;
}

void Insert(int index,int val){
	int key=val%HASH_CAP;
	if (hashPres[key]==-1){
		hashPres[key]=hashNodes.size();
		hashNodes.push_back(HNode(val,index,-1));
	}
	else{
		int i=hashPres[key];
		for (;hashNodes[i].nextNode!=-1;){
			i=hashNodes[i].nextNode;
		}
		hashNodes[i].nextNode=hashNodes.size();
		hashNodes.push_back(HNode(val,index,-1));
	}
}


int main (){
	fin>>n>>d;
	hashPres.resize(HASH_CAP,-1);
	int ptr=0;
	int res=0;
	int zeroPos=-1;
	int cycleStart=-1;
	while (true){
		if (ptr<n.length()-1){
			res=res*10+n[ptr]-'0';
			int p=res/d;
			ps.push_back(p);
			res=res%d;
			ptr++;
		}
		else if (ptr==n.length()-1){
			res=res*10+n[ptr]-'0';
			int p=res/d;
			ps.push_back(p);
			res=res%d;
			ptr++;
			if (res==0){
				break;
			}
			else{
				zeroPos=ps.size()-1;
			}
		}
		else {
			res=res*10;
			int p=res/d;
			int nextRes=res%d;
			if (nextRes==0){
				ps.push_back(p);
				break;
			}
			else{
				int cycleIdx=Exist(res);
				if (cycleIdx!=-1){
					cycleStart=cycleIdx+zeroPos+1;
					break;
				}
				ps.push_back(p);
				resVec.push_back(res);
				Insert(resVec.size()-1,res);
				res=nextRes;
			}
		}
	}

	bool conZeroFlag=true;
	int outputCount=0;
	for (int i=0;i<ps.size();i++){
		if (i<zeroPos){
			if (conZeroFlag){
				if (ps[i]){
					conZeroFlag=false;
					fout<<ps[i];
					outputCount++;
					if (outputCount==76){
						fout<<endl;
						outputCount=0;
					}
				}
			}
			else{
				fout<<ps[i];
				outputCount++;
				if (outputCount==76){
					fout<<endl;
					outputCount=0;
				}

			}
		}
		else if (i==zeroPos){
			fout<<ps[i];
			outputCount++;
			if (outputCount==76){
				fout<<endl;
				outputCount=0;
			}
			fout<<".";
			outputCount++;
			if (outputCount==76){
				fout<<endl;
				outputCount=0;
			}

		}
		else{
			if (i==cycleStart){
				fout<<"(";
				outputCount++;
				if (outputCount==76){
					fout<<endl;
					outputCount=0;
				}

			}
			fout<<ps[i];
			outputCount++;
			if (outputCount==76){
				fout<<endl;
				outputCount=0;
			}

		}
	}
	if (cycleStart!=-1){
		fout<<")";
	}
	if (zeroPos==-1){
		fout<<".0";
	}
	fout<<endl;
	return 0;
}
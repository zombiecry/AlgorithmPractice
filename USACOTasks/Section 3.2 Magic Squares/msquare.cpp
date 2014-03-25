/*
ID: yezhiyo1
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("msquare.in");
ofstream fout("msquare.out");
struct State{
	unsigned int states;
	string seqStr;
	State (){}
	bool operator ==(const State &s) const{
		return states==s.states;
	}
};
typedef std::queue <State> StateQueue;



StateQueue sQue;
StateQueue invSQue;
State startStat;
State goalStat;

int trans[3][8]={{7,6,5,4,3,2,1,0},
				 {3,0,1,2,5,6,7,4},
				 {0,6,1,3,4,2,5,7}};
int invTrans[3][8]={{7,6,5,4,3,2,1,0},
			        {1,2,3,0,7,4,5,6},
				    {0,2,5,3,4,6,1,7}};

char sTrans[3]={'A','B','C'};


void GenNode(State &newState,const State &oldState,int transMat[][8],int transType,bool invFlag=false){
	if (invFlag){
		newState.seqStr=sTrans[transType]+oldState.seqStr;
	}
	else{
		newState.seqStr=oldState.seqStr+sTrans[transType];
	}
	newState.states=oldState.states;
	for (int i=0;i<8;i++){
		char *p1=(char *)&newState.states;
		char *p2=(char *)&oldState.states;
		char ch1,ch2;
		if (transMat[transType][i]%2==0){
			ch2=p2[transMat[transType][i]/2]&0xf0;
			ch2=ch2>>4;
		}
		else{
			ch2=p2[transMat[transType][i]/2]&0x0f;
		}
		ch2=ch2&0x0f;
		if (i%2==0){
			ch1=p1[i/2]&0x0f;
			ch2=ch2<<4;
		}
		else{
			ch1=p1[i/2]&0xf0;
		}

		p1[i/2]=ch1|ch2;
	}
}

std::vector <State> levelState;
std::vector <State> invLevelState;



string transStr;
int start1=0;
int start2=0;
bool findFlag;
void FindSection(int s1,int len1,int s2,int len2){
	for (int i=s1;i<len1;i++){
		for (int j=s2;j<len2;j++){
			if (levelState[i]==invLevelState[j]){
				string str1=levelState[i].seqStr;
				string str2=invLevelState[j].seqStr;
				string curStr=str1+str2;
				if (!findFlag){
					findFlag=true;
					transStr=curStr;
				}
				else{
					transStr=std::min <string> (transStr,curStr);
				}
			}		
		}
	}

}

bool FindInLevel(){
	findFlag=false;
	int n1=levelState.size();
	int n2=invLevelState.size();
	FindSection(0,start1,start2,n2);
	FindSection(start1,n1,0,n2);
	start1=levelState.size();
	start2=invLevelState.size();
	return findFlag;
}

State curState;
State curInvState;
bool expandFlag=true;
bool invExpandFlag=true;

void Expan(){
	if (!expandFlag){
		return;
	}
	for (int i=0;i<levelState.size();i++){
		if (curState==levelState[i]){
			expandFlag=false;
		}
	}
	sQue.pop();
	levelState.push_back(curState);
	if (expandFlag){
		for (int i=0;i<3;i++){
			State newState;
			GenNode(newState,curState,trans,i);
			sQue.push(newState);
		}
	}

}

void InvExpan(){
	if (!invExpandFlag){
		return;
	}
	for (int i=0;i<invLevelState.size();i++){
		if (curInvState==invLevelState[i]){
			if (curInvState.seqStr>invLevelState[i].seqStr){
				invExpandFlag=false;
			}
		}
	}
	invSQue.pop();
	invLevelState.push_back(curInvState);
	if (invExpandFlag){
		for (int i=2;i>=0;i--){
			State newState;
			GenNode(newState,curInvState,invTrans,i,true);
			invSQue.push(newState);
		}
	}
}
int main (){
	startStat.states=0x78563412;
	for (int i=0;i<4;i++){
		short a,b;
		fin>>a>>b;
		a=a<<4;
		a=a|b;
		char *p=(char *)&goalStat.states;
		p[i]=a;
	}
	sQue.push(startStat);	
	invSQue.push(goalStat);
	int curLevel=0;
	while (!sQue.empty() && !invSQue.empty()){
		curState=sQue.front();
		curInvState=invSQue.front();
		expandFlag=true;
		invExpandFlag=true;
		if (curState.seqStr.length()==curInvState.seqStr.length()){
			if(curState.seqStr.length()>curLevel){
				if (FindInLevel()){
					break;
				}
				curLevel++;
			}
		}
		else{
			if (curState.seqStr.length()>curInvState.seqStr.length()){
				expandFlag=false;
			}
			else{
				invExpandFlag=false;
			}
		}
		Expan();
		InvExpan();
	}
	fout<<transStr.length()<<endl;
	fout<<transStr<<endl;
	return 0;
}
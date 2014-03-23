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
	std::vector <int> states;
	string seqStr;
	State ():states(8,0){}
	bool operator ==(const State &s) const{
		for (int i=0;i<states.size();i++){
			if (states[i]!=s.states[i]){
				return false;
			}
		}
		return true;
	}
};
typedef std::queue <State> StateQueue;



StateQueue sQue;
StateQueue invSQue;
std::vector <string> ignoreVec;
std::vector <string> invIgnoreVec;

State startStat;
State goalStat;



int trans[3][8]={{7,6,5,4,3,2,1,0},
				 {3,0,1,2,5,6,7,4},
				 {0,6,1,3,4,2,5,7}};
int invTrans[3][8]={{7,6,5,4,3,2,1,0},
			        {1,2,3,0,7,4,5,6},
				    {0,2,5,3,4,6,1,7}};

char sTrans[3]={'A','B','C'};
void GenNode(State &newState,const State &oldState,int transType){
	newState.seqStr=oldState.seqStr+sTrans[transType];
	for (int i=0;i<8;i++){
		newState.states[i]=oldState.states[trans[transType][i]];
	}
}

void InvGenNode(State &newState,const State &oldState,int transType){
	newState.seqStr=sTrans[transType]+oldState.seqStr;
	for (int i=0;i<8;i++){
		newState.states[i]=oldState.states[invTrans[transType][i]];
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
				if (!findFlag){
					findFlag=true;
					transStr=levelState[i].seqStr+invLevelState[j].seqStr;
				}
				else{
					transStr=std::min <string> (transStr,levelState[i].seqStr+invLevelState[j].seqStr);
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

int main (){
	for (int i=0;i<8;i++){
		fin>>goalStat.states[i];
		startStat.states[i]=i+1;
	}
	sQue.push(startStat);
	invSQue.push(goalStat);
	int curLevel=0;
	while (!sQue.empty() && !invSQue.empty()){
		State curState=sQue.front();
		State curInvState=invSQue.front();
		sQue.pop();
		invSQue.pop();
		if (curState.seqStr.length()>curLevel){
			if (FindInLevel()){
				break;
			}
			curLevel++;
		}
		bool expandFlag=true;
		bool invExpandFlag=true;
		
		if (curLevel!=0 ){
			if (curState==startStat){
				ignoreVec.push_back(curState.seqStr);
				expandFlag=false;
			}
			if (curInvState==goalStat){
				invIgnoreVec.push_back(curInvState.seqStr);
				invExpandFlag=false;
			}
		}
		for (int i=0;i<ignoreVec.size();i++){
			if (curState.seqStr.find(ignoreVec[i])!=string::npos){
				expandFlag=false;
				break;
			}
		}
		for (int i=0;i<invIgnoreVec.size();i++){
			if (curInvState.seqStr.find(invIgnoreVec[i])!=string::npos){
				invExpandFlag=false;
				break;
			}
		}
		if (expandFlag){
			levelState.push_back(curState);
			for (int i=0;i<3;i++){
				State newState;
				GenNode(newState,curState,i);
				sQue.push(newState);
			}
		}
		if (invExpandFlag){
			invLevelState.push_back(curInvState);
			for (int i=0;i<3;i++){
				State newState;
				InvGenNode(newState,curInvState,i);
				invSQue.push(newState);
			}
		}
	}

	fout<<transStr.length()<<endl;
	fout<<transStr<<endl;
	return 0;
}
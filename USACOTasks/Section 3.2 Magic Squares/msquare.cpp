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
};
typedef std::queue <State> StateQueue;

StateQueue sQue;
std::vector <string> ignoreVec;
std::vector <int> goal(8);
State startStat;


bool GoalState(const State &s){
	for (int i=0;i<goal.size();i++){
		if (s.states[i]!=goal[i]){
			return false;
		}
	}
	return true;
}


bool StartState(const State &s){
	for (int i=0;i<startStat.states.size();i++){
		if (s.states[i]!=startStat.states[i]){
			return false;
		}
	}
	return true;
}

int trans[3][8]={{7,6,5,4,3,2,1,0},
				 {3,0,1,2,5,6,7,4},
				 {0,6,1,3,4,2,7,5}};
char sTrans[3]={'A','B','C'};
void GenNode(State &newState,const State &oldState,int transType){
	newState.seqStr=oldState.seqStr+sTrans[transType];
	for (int i=0;i<8;i++){
		newState.states[i]=oldState.states[trans[transType][i]];
	}
}



int main (){
	for (int i=0;i<8;i++){
		fin>>goal[i];
		startStat.states[i]=i+1;
	}
	sQue.push(startStat);
	while (!sQue.empty()){
		const State &curState=sQue.front();
		if (GoalState(curState)){
			break;
		}
		else {
			if (StartState(curState)&&curState.seqStr.length()){
				ignoreVec.push_back(curState.seqStr);
				sQue.pop();
			}
			else{	//new state
				bool ignoreFlag=false;
				for (int i=0;i<ignoreVec.size();i++){
					if (curState.seqStr.find(ignoreVec[i])!=string::npos){
						ignoreFlag=true;
						break;
					}
				}
				if (!ignoreFlag){
					State fatherState=curState;
					sQue.pop();
					for (int i=0;i<3;i++){
						State newState;
						GenNode(newState,fatherState,i);
						sQue.push(newState);
					}
				}
				else{
					sQue.pop();
				}
			}
		}
	}

	fout<<sQue.front().seqStr.length()<<endl;
	fout<<sQue.front().seqStr<<endl;

	return 0;
}
/*
ID: yezhiyo1
PROG: contact
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
typedef std::vector <string> scStrList;
std::vector <scStrList > strList;
int strCount=0;
struct Node{
	int num;
	int strIndex;
};
std::vector <Node> nodes;
bool MyCompareLarger(const Node &n1,const Node &n2){
	return n1.num>n2.num;
}

bool MyStrCompareL(const string &s1,const string &s2){
	if (s1.length()==s2.length()){
		return s1<s2;
	}
	else{
		return s1.length()<s2.length();
	}
}

void Insert(string str){
	Node newN;
	newN.num=patternMap[str];
	if (nodes.size()<N){	//new an item at end
		newN.strIndex=nodes.size();
		strList[newN.strIndex].clear();
		strList[newN.strIndex].push_back(str);
		nodes.push_back(newN);
	}
	else{	//replace the last item
		newN.strIndex=nodes[nodes.size()-1].strIndex;
		strList[newN.strIndex].clear();
		strList[newN.strIndex].push_back(str);
	}
	int i=nodes.size()-2;
	for (;i>=0;i--){
		if (MyCompareLarger(newN,nodes[i])){
			nodes[i+1]=nodes[i];
		}
		else {
			break;
		}
	}
	nodes[i+1]=newN;
}

void OnChanged(string str,int num){
	bool find=false;
	int index;
	for (int i=0;i<nodes.size();i++){
		if (nodes[i].num==num){
			find=true;
			index=i;
		}
	}
	if (find){
		strList[nodes[index].strIndex].push_back(str);
		return;
	}
	if (nodes.size()<N){
		Insert(str);	
	}
	else{
		if (patternMap[str]>nodes[N-1].num){
			Insert(str);
		}
	}
}

int main (){
	fin>>A>>B>>N;
	strList.resize(N+1);
	string totStr;
	string line;
	while (fin>>line){
		totStr+=line;
	}

	for (int i=0;i<totStr.length();i++){
		for (int j=A;j<=B;j++){
			if (i+j<=totStr.length()){
				string curTemp=totStr.substr(i,j);
				if (patternMap.count(curTemp)){
					patternMap[curTemp]++;
				}
				else{
					patternMap[curTemp]=1;
				}
			}
		}
	}
	std::map <string,int>::iterator iter=patternMap.begin();
	for (;iter!=patternMap.end();iter++){
		OnChanged(iter->first,iter->second);
	}
	int total=std::min((int)nodes.size(),N);
	for (int i=0;i<total;i++){
		std::sort(strList[nodes[i].strIndex].begin(),strList[nodes[i].strIndex].end(),MyStrCompareL);
	}
	for (int i=0;i<total;i++){
		fout<<nodes[i].num<<endl;
		int j=0;
		for (;j<strList[nodes[i].strIndex].size()-1;j++){
			fout<<strList[nodes[i].strIndex][j];
			if (j>1 && (j+1)%6==0 ){
				fout<<endl;
			}
			else{
				fout<<" ";
			}
		}
		fout<<strList[nodes[i].strIndex][j]<<endl;
	}
	return 0;
}
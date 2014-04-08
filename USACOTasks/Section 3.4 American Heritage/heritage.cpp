/*
ID: yezhiyo1
PROG: heritage
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("heritage.in");
ofstream fout("heritage.out");
string inStr;
string preStr;

struct Node{
	char val;
	int left;
	int right;
	Node(int _val,int _left,int _right){}
	Node(){}
};
std::vector <Node> nodes;
int root;

void BuildTree(int root,int preStart,int inStart,int inEnd){
	char rotChar=preStr[preStart];
	nodes[root].val=preStr[preStart];
	int i=inStart;
	for (;i<=inEnd;i++){
		if (inStr[i]==rotChar){
			break;
		}
	}
	if (i>inStart){
		nodes.push_back(Node(0,0,0));
		nodes[root].left=nodes.size()-1;
		BuildTree(nodes.size()-1,preStart+1,inStart,i-1);
	}
	else{
		nodes[root].left=-1;
	}
	if (i<inEnd){
		nodes.push_back(Node(0,0,0));
		nodes[root].right=nodes.size()-1;
		BuildTree(nodes.size()-1,preStart+i-inStart+1,i+1,inEnd);
	}
	else{
		nodes[root].right=-1;
	}
}


void PostOrder(int root){
	if (nodes[root].left!=-1){
		PostOrder(nodes[root].left);
	}
	if (nodes[root].right!=-1){
		PostOrder(nodes[root].right);
	}
	fout<<nodes[root].val;
}


int main (){
	fin>>inStr;
	fin>>preStr;
	Node root;
	nodes.push_back(root);
	BuildTree(0,0,0,inStr.length()-1);
	PostOrder(0);
	fout<<endl;
	return 0;
}
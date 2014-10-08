#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include<queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;
class Solution {
public:
	int n,m;
	vector <vector<char>>    c;
	bool Check(int p,int q,vector<vector<char> > &board){
		vector <bool> cm(10,false);
		for (int i=0;i<n;i++){
			char ch=c[i][q];
			if (ch=='.'){continue;}
			ch=c[i][q]-'0';
			if (!cm[ch]){
				cm[ch]=true;
			}
			else{return false;}
		}
		fill(cm.begin(),cm.end(),false);
		for (int i=0;i<m;i++){
			char ch=c[p][i];
			if (ch=='.'){continue;}
			ch=c[p][i]-'0';
			if (!cm[ch]){
				cm[ch]=true;
			}
			else{return false;}
		}
		return true;
	}
	bool Solve(int p,int q,vector<vector<char> > &board){
		if (p==n){return true;}
		int nq=q+1;
		int np=p;
		if (nq>m-1){
			nq=0;
			np++;
		}
		if (board[p][q]!='.'){  //have number
			return Solve(np,nq,board);
		}
		for (int i=1;i<10;i++){
			c[p][q]=i+'0';
			if (!Check(p,q,board)){continue;}
			if (Solve(np,nq,board)){
				return true;
			}
		}
		//back track
		c[p][q]='.';
		return false;
	}
	void solveSudoku(vector<vector<char> > &board) {
		n=board.size();
		if (n==0){return;}
		m=board[0].size();
		c=board;
		Solve(0,0,board);
		board=c;
	}
};
int main (){
	Solution *sol=new Solution;
	string a[]={"53..7....","6..195...",".98....6.","8...6...3","4..8.3..1","7...2...6",".6....28.","...419..5","....8..79"};
	int n=sizeof(a)/sizeof(a[0]);
	vector<vector<char>> b;
	for (int i=0;i<n;i++){
		b.push_back(vector<char>(a[i].c_str(),a[i].c_str()+a[i].length()));
	}
	sol->solveSudoku(b);
	for (int i=0;i<b.size();i++){
		for (int j=0;j<b[i].size();j++){
			cout<<b[i][j];
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
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
typedef pair<int,int> scpair;
class Solution {
public:
	int                   color;
	int m,n;
	int BFS(int x,int y,vector<vector<char>> &board){
		list <scpair> que;
		que.push_back(scpair(x,y));
		board[y][x]=color;
		int res=0;
		while (!que.empty()){
			scpair t=que.front();
			que.pop_front();
			int x=t.first;
			int y=t.second;

			if (x<=0 || x>=m-1 ||
				y<=0|| y>=n-1){
					res=1;
			}
			for (int i=-1;i<2;i++) for (int j=-1;j<2;j++){
				if (i!=0 && j!=0){continue;}
				if (i==0 && j==0){continue;}
				if (x+j<0 || x+j>m-1||
					y+i<0 || y+i>n-1){continue;}
				//cout<<x+j<<" "<<y+i<<endl;
				if (board[y+i][x+j]=='O'){
					board[y+i][x+j]=color;
					que.push_back(scpair(x+j,y+i));
				}
			}   
		}
		return res;
	}
	void solve(vector<vector<char>> &board) {
		n=board.size();
		if (n==0){return;}
		m=board[0].size();
		if (m==0){return;}
		color=0;
		for (int i=0;i<n;i++) for (int j=0;j<m;j++){
			if (board[i][j]=='O'){  //found a start point to dfs
				int f=BFS(j,i,board);
				if (!f){
					for (int p=0;p<n;p++) for (int q=0;q<m;q++){
						if (board[p][q]==color){
							board[p][q]='X';
						}
					}
				}
				color--;
			}
		}
		for (int i=0;i<n;i++) for (int j=0;j<m;j++){
			if (board[i][j]!='X'){board[i][j]='O';}
		}
	}
};

int main (){ 
	Solution *sol=new Solution;
	//char * a[]={"XOOOOOOOOOOOOOOOOOOO","OXOOOOXOOOOOOOOOOOXX","OOOOOOOOXOOOOOOOOOOX","OOXOOOOOOOOOOOOOOOXO","OOOOOXOOOOXOOOOOXOOX","XOOOXOOOOOXOXOXOXOXO","OOOOXOOXOOOOOXOOXOOO","XOOOXXXOXOOOOXXOXOOO","OOOOOXXXXOOOOXOOXOOO","XOOOOXOOOOOOXXOOXOOX","OOOOOOOOOOXOOXOOOXOX","OOOOXOXOOXXOOOOOXOOO","XXOOOOOXOOOOOOOOOOOO","OXOXOOOXOXOOOXOXOXOO","OOXOOOOOOOXOOOOOXOXO","XXOOOOOOOOXOXXOOOXOO","OOXOOOOOOOXOOXOXOXOO","OOOXOOOOOXXXOOXOOOXO","OOOOOOOOOOOOOOOOOOOO","XOOOOXOOOXXOOXOXOXOO"};
	//char *a[]={"OXO","XOX","OXO"};
	char *a[]={"XXXXXXXOXXXXXXXXXXXX","XXXXXXOXXXOXOXOXXXXX","XXXXXXXXXXXOOOXXXXOO","XOXOXXXXOXOXOXXOXXXX","XOXXXXXXOXXOOXXXOXXX","OXXXXXOXXOXOOXXXOXXX","XXXXXXXXOXXXOXOXXXXX","XXXXXOXXXXXOXOXOXOXX","OXXXXXXXOXOXXOXXXOOX","OXOOOXXXXXXOXXXOXOXO","OXXXXXXXXXOOOOXXXXXX","XOXXOXXXXXXXXXXXOXOX","XXXXXXOXOXXOXOXXXXXX","XXXXXXXXXXXOXXXXXXXO","XXOXOXXXOXXXXXXXXXXX","XXXXXXOXXXOXXXOXXOOX","XOXXXXXXXXXXOOXXXXXX","XOOXXXOOXXOXXXOOXXXX","XXXOXXOOOXOOXXXXOOXX","XXXXXXXXOXXXXXXXOXOX"};
	int n=sizeof(a)/sizeof(a[0]);
	int m=strlen(a[0]);
	vector <vector<char>> A;
	for (int i=0;i<n;i++){
		A.push_back(vector<char>(a[i],a[i]+m));
	}
	sol->solve(A);
	return 0;
}
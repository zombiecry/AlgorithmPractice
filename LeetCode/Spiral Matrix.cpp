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
	int cn,cm;
	vector <int> tot;
	vector<vector<int> > matrix;
	void Print(){
		int l=(m-cm)/2;
		int u=(n-cn)/2;
		int r=m-l-1;
		int d=n-l-1;

		if (l==r){
			for (int i=u;i<=d;i++){
				tot.push_back(matrix[i][l]);
			}
			return;
		}
		if (u==d){
			for (int i=l;i<=r;i++){
				tot.push_back(matrix[u][i]);
			}
			return;
		}

		for (int i=l;i<r;i++){
			tot.push_back(matrix[u][i]);
		}
		for (int i=u;i<d;i++){
			tot.push_back(matrix[i][r]);
		}
		for (int i=r;i>l;i--){
			tot.push_back(matrix[d][i]);
		}
		for (int i=d;i>u;i--){
			tot.push_back(matrix[i][l]);
		}
	}
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		this->matrix=matrix;
		n=matrix.size();
		if (n==0){return tot;}
		m=matrix[0].size();
		if (m==0){return tot;}
		cn=n;
		cm=m;
		while(cn>0 && cm>0){
			Print();
			cn-=2;
			cm-=2;
		}
		return tot;
	}
};

int main (){
	Solution *sol=new Solution;
	vector<vector<int>> mat;
	mat.push_back(vector<int>(1,1));
	vector<int> v=sol->spiralOrder(mat);
	for (int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	system("pause");
	return 0;
}
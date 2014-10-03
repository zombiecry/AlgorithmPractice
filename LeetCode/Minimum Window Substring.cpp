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
	string minWindow(string S, string T) {
		map <char,int> cm;
		map <char,int> stat;
		n=S.length();
		m=T.length();
		for (int i=0;i<m;i++){
			if (cm.find(T[i])==cm.end()){
				cm[T[i]]=1;
			}
			else{
				cm[T[i]]++;
			}
			stat[T[i]]=0;
		}
		int res=numeric_limits<int>::max();
		typedef pair <int,int> scpair;
		scpair minw;
		int q=0;
		int count=0;
		for (int i=0;i<n;i++){
			bool endFlag=false;
			while(count<m){
				q++;
				if (q>n){
					endFlag=true;
					break;
				}
				if (cm.find(S[q-1])==cm.end()){continue;}
				if (stat[S[q-1]]<cm[S[q-1]]){
					count++;
				}
				stat[S[q-1]]++;
			}
			if (endFlag){break;}
			if (res > q-i){
				res=q-i;
				minw=scpair(i,q);    
			}
			if (cm.find(S[i])==cm.end()){continue;}
			stat[S[i]]--;
			if (stat[S[i]]<cm[S[i]]){count--;}
		}
		if (res>n){return "";}//no win
		return S.substr(minw.first,minw.second-minw.first);
	}
};
int main (){
	Solution *sol=new Solution;
	string T="a";
	string S="aa";
	cout<<sol->minWindow(T,S)<<endl;
	return 0;
}
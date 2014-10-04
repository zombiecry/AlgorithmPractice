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
	vector<string> fullJustify(vector<string> &words, int L) {
		n=words.size();
		int s=0;
		vector <string> res;
		while(s<n){
			int count=0;
			int end=n;
			int chCount=0;
			bool contFlag=false;
			for (int i=s;i<n;i++){
				if (i==s){
					if (count+words[i].length()>L){
						end=i;
						break;
					}
				}
				else{
					if (count+words[i].length()+1>L){
						end=i;
						break;
					}
				}
				chCount+=words[i].length();
				count+=words[i].length();
				if (i>s){count+=1;}
			}
			int spaceNum=L-chCount;
			int betNum=end-s-1;
			if (betNum==0){betNum=1;}
			int unitNum=spaceNum / betNum;
			int redNum=spaceNum % betNum;
			string cur;
			if (end==n){
				for (int i=s;i<end;i++){
					if (i>s){
						cur+=" ";
					}
					cur+=words[i];
				}
				if (L>cur.length()){
					cur+=string(L-cur.length(),' ');
				}
				res.push_back(cur);
				s=end;
				continue;
			}
			for (int i=s;i<end;i++){
				cur+=words[i];
				if (i+1==end && end-s>1){continue;}
				cur+=string(unitNum,' ');
				if (redNum){
					cur+=" ";
					redNum--;
				}
			}
			res.push_back(cur);
			s=end;
		}
		return res;
	}
};

int main(){
	Solution *sol=new Solution;
	string arr[]={"a","b","c","d","e"};
	vector <string> a(arr,arr+5);
	cout<<"["<<sol->fullJustify(a,3)[0]<<"]"<<endl;
	
	return 0;
}
// BEGIN CUT HERE 

// END CUT HERE
#line 5 "EllysCandyGame.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
using namespace std;
typedef long long int scLi;
typedef long long unsigned int scLui;

typedef std::pair <int,int> scPair2i;
typedef std::vector <int> scVeci;
typedef std::vector <scPair2i> scVec2i;
typedef std::stack  <int> scStacki;
typedef std::queue  <int> scQueuei;
typedef std::set    <int> scSeti;
typedef std::map<int,int> scMapii;
typedef std::map<int,int>::iterator scMapiiIter;
typedef std::map<int,int>::reverse_iterator scMapiiRevIter;
#define tr(container,it)    \
    for (it=container.begin();it!=container.end();it++)
#define trRev(container,it)    \
	for (it=container.rbegin();it!=container.rend();it++)
#define scFor0(x,num) \
	for (int x=0;x<num;x++)
#define scFor1(x,start,num) \
	for (int x=start;x<num;x++)
const int INF=0x7fffffff;
int m,n;


class EllysCandyGame
        { 
        public: 
			vector <int> sweets;
			map    <string,int> mem;
			string Get(string s,int p){
				string res=s;
				int pre=p-1;
				int pos=p+1;
				if (pre>=0){
					int t=s[pre]-'0';
					res[pre]=t*2+'0';
				}
				if (pos<n){
					int t=s[pos]-'0';
					res[pos]=t*2+'0';
				}
				res[p]='0';
				return res;
			}

			int GetVal(string s,int p){
				int t=s[p]-'0';
				return t*sweets[p];
			}
			int Solve(string s){
				int count=0;
				int p1=-1;
				scFor0(i,n){
					if (s[i]>'0'){
						count++;
						p1=i;
					}
				}
				if (count==0){
					return 0;
				}
				if (count==1){
					return GetVal(s,p1);
				}
				if (mem.count(s)){
					return mem[s];
				}
				int res=-INF;
				scFor0(i,n){
					if (s[i]<='0'){
						continue;
					}
					string s1=Get(s,i);
					int sol1=Solve(s1);
					int t=GetVal(s,i) - sol1;
					if (t>res){
						res=t;
					}
				}
				mem[s]=res;
				return mem[s];
			}
        string getWinner(vector <int> sweets) 
            { 
				this->sweets=sweets;
				n=sweets.size();
				string s;
				s.resize(n);
				scFor0(i,n){
					if (sweets[i]){
						s[i]=s[i]+'1';
					}
					else{
						s[i]=s[i]+'0';
					}
				}
				int res=Solve(s);
				if (res>0){
					return "Elly";
				}
				else if (res<0){
					return "Kris";
				}
				else{
					return "Draw";
				}

            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {20, 50, 70, 0, 30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Kris"; verify_case(0, Arg1, getWinner(Arg0)); }
	void test_case_1() { int Arr0[] = {42, 13, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Elly"; verify_case(1, Arg1, getWinner(Arg0)); }
	void test_case_2() { int Arr0[] = {10, 20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Draw"; verify_case(2, Arg1, getWinner(Arg0)); }
	void test_case_3() { int Arr0[] = {3, 1, 7, 11, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Kris"; verify_case(3, Arg1, getWinner(Arg0)); }
	void test_case_4() { int Arr0[] = {41, 449, 328, 474, 150, 501, 467, 329, 536, 440}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Kris"; verify_case(4, Arg1, getWinner(Arg0)); }
	void test_case_5() { int Arr0[] = {177, 131, 142, 171, 411, 391, 17, 222, 100, 298}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Elly"; verify_case(5, Arg1, getWinner(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        EllysCandyGame ___test; 
        ___test.run_test(5); 
        system("pause");
        } 
    // END CUT HERE 

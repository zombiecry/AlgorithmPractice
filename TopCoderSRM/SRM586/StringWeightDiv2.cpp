// BEGIN CUT HERE 

// END CUT HERE
#line 5 "StringWeightDiv2.cpp"
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
using namespace std;


int m,n;
const int MODULAR=1000000009;
class StringWeightDiv2
        { 
        public: 
			int comb[27][27];
			int dp[1001][27];
			//clac the combination use C(a,b)=C(a-1,b-1)+C(a-1,b)
			int CalcC(int n,int m){
				if (n==0 && m==0){return 1;}
				if (n==0){return 0;}
				if (m==0){return 1;}
				if (n<m){return 0;}
				if (comb[n][m]!=-1){return comb[n][m];}
				int res=(CalcC(n-1,m-1)+CalcC(n-1,m))%MODULAR;
				comb[n][m]=res;
				return res;
			}
			//how many ways for [0,p] with l charectors unused
			int Solve(int p,int l){
				if (p==-1){return l==0;}
				if (dp[p][l]!=-1){return dp[p][l];}
				long long res=0;
				if (l>0){	//begin a new consecutive seria
					res+=(long long)Solve(p-1,l-1)*CalcC(l,1);
					res%=MODULAR;
				}
				if (l<26){	//continue with last charactor
					res+=Solve(p-1,l);
					res%=MODULAR;
				}
				dp[p][l]=(int)res;
				return (int)res;
			}
        int countMinimums(int L) 
            { 
				memset(comb,-1,sizeof(comb));
				if (L<=26){		//just select unique charactors in the permutation
					long long res=1;
					for (int i=0;i<L;i++){
						res*=CalcC(26-i,1);
						res%=MODULAR;
					}
					return res;
				}
				else{
					//when L>26, the string should meet:
					//1)use all the 26 characters
					//2)for one specify character, its appearance must be consecutive.
					memset(dp,-1,sizeof(dp));
					return Solve(L-1,26);
				}
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 26; verify_case(0, Arg1, countMinimums(Arg0)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 650; verify_case(1, Arg1, countMinimums(Arg0)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 488801539; verify_case(2, Arg1, countMinimums(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        StringWeightDiv2 ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

// BEGIN CUT HERE 

// END CUT HERE
#line 5 "FoxAndShogi.cpp"
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
const int MODULAR=1000000007;

int m,n;
class FoxAndShogi
        { 
        public: 
			string		 s;
			vector <int> A;
			int			 dp[50][50];
			//the memo sol
			int Solve(int p,int q){
				if (p==-1){return 1;}
				if (q==0){return 0;}
				if (q <= A[p] && s[A[p]]=='D'){return 0;}
				if (dp[p][q]!=-1){return dp[p][q];}
				int res=0;
				if (s[A[p]]=='D'){
					for (int i=A[p];i<q;i++){
						res+=Solve(p-1,i);
						res%=MODULAR;
					}
				}
				if (s[A[p]]=='U'){
					for (int i=0;i<q && i<=A[p];i++){
						res+=Solve(p-1,i);
						res%=MODULAR;
					}
				}
				dp[p][q]=res;
				return res;
			}
			//the dp sol
			//dp[i][j]: there left the first i items not determined
			//the already determined last items' state is j
			//how many ways for the state (i,j)?
			int DPSolve(){
				int dp[51][51];
				for (int i=0;i<=n;i++){
					dp[0][i]=1;
				}
				for (int i=1;i<=m;i++){
					for (int j=0;j<=n;j++){
						dp[i][j]=0;
						if (j<=A[i-1] && s[A[i-1]]=='D'){continue;}
						if (s[A[i-1]]=='D'){
							for (int k=A[i-1];k<j;k++){
								dp[i][j]+=dp[i-1][k];
								dp[i][j]%=MODULAR;
							}
						}
						else{
							for (int k=0;k<=A[i-1] && k<j;k++){
								dp[i][j]+=dp[i-1][k];
								dp[i][j]%=MODULAR;
							}
						}
					}
				}
				return dp[m][n];
			}
        int differentOutcomes(vector <string> board) 
            { 
				long long res=1;
				n=board.size();
				for (int i=0;i<n;i++){
					A.resize(0);
					s.resize(n);
					for (int j=0;j<n;j++){
						s[j]=board[j][i];
						if (s[j]=='D' || s[j]=='U'){
							A.push_back(j);
						}
					}
					m=A.size();
					//dp for s

#if 0
					memset(dp,-1,sizeof(dp));
					res *=Solve(m-1,n);
					res %=MODULAR;
#else
					res *=DPSolve();
					res %=MODULAR;
#endif
				}
				return int(res);

            } 

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".D.",
 "...",
 "..."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, differentOutcomes(Arg0)); }
	void test_case_1() { string Arr0[] = {".D.",
 "...",
 ".U."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, differentOutcomes(Arg0)); }
	void test_case_2() { string Arr0[] = {"DDDDD",
 ".....",
 ".....",
 ".....",
 "....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3125; verify_case(2, Arg1, differentOutcomes(Arg0)); }
	void test_case_3() { string Arr0[] = {"DDDDD",
 "U....",
 ".U...",
 "..U..",
 "...U."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 900; verify_case(3, Arg1, differentOutcomes(Arg0)); }
	void test_case_4() { string Arr0[] = {"....D..",
 "U....D.",
 "D.D.U.D",
 "U.U...D",
 "....U..",
 "D.U...D",
 "U.U...."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2268; verify_case(4, Arg1, differentOutcomes(Arg0)); }
	void test_case_5() { string Arr0[] = {"DDDDDDDDDD",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 ".........."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999937; verify_case(5, Arg1, differentOutcomes(Arg0)); }
	void test_case_6() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(6, Arg1, differentOutcomes(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        FoxAndShogi ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

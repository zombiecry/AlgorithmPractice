// BEGIN CUT HERE 

// END CUT HERE
#line 5 "FlippingBitsDiv2.cpp"
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
class FlippingBitsDiv2
        { 
        public: 
			vector <int> A;
			vector <int> c[2];
			int dp[2501][2][2];
			int Solve(int t,int p,int q){
				if (dp[t][p][q]!=-1){return dp[t][p][q];}
				if (t==0){	
					if (p==1 && q==1){		//non-flip at all(q==1) and infact previous choice is 1
						return 1;
					}
					return 0;
				}
				int res=numeric_limits<int>::max();
				//0: flip cur group verse vice
				for (int i=0;i<2;i++){
					int change=q;		//has a change happened?
					int curChange=0;	//if current change from previous
					if (t!=m){
						curChange=i^p;
						if (change==1){
							change=!(p ^ i);
						}
					}
					res=min(res,curChange+c[i][t-1]+Solve(t-1,i,change));
				}
				dp[t][p][q]=res;
				return res;
			}
        int getmin(vector <string> S, int M) 
            { 
				memset(dp,-1,sizeof(dp));
				//devide S into |S|/M groups
				for (int i=0;i<S.size();i++) for (int j=0;j<S[i].length();j++){
					A.push_back(S[i][j]-'0');
				}
				n=A.size();
				m=n/M;
				c[0].resize(m,0);
				c[1].resize(m,0);
				//statistic the op of flipping or non-flipping bits of every group.
				for (int i=0;i<m;i++) for (int j=0;j<M;j++){
					int p=i*M+j;
					if (A[p]==0){c[0][i]++;}
					else if (A[p]==1){c[1][i]++;}
				}
				//first m groups, last choice is 0, allflip flag is 1
				return Solve(m,0,1);
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"00111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, getmin(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"00111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getmin(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, getmin(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"00100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 2; verify_case(3, Arg2, getmin(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"00010","11010110","1010111","110001010","0110001100"
,"000110110","011010101","00","111","100"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 31; verify_case(4, Arg2, getmin(Arg0, Arg1)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        FlippingBitsDiv2 ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

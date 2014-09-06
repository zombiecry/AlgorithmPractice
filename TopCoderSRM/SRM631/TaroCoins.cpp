// BEGIN CUT HERE 

// END CUT HERE
#line 5 "TaroCoins.cpp"
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
class TaroCoins
        { 
        public: 
			long long num;
			long long dp[65][4];
			//the memo search
			long long Solve(int p,int r){
				if (p==-1){
					if (r==0){return 1;}
					return 0;
				}
				if (dp[p][r]!=-1){return dp[p][r];}
				long long res=0;
				if (num>>p &1){
					r++;
				}
				for (int i=0;i<=2;i++){
					if ((r-i) <0){break;}
					if ((r-i)*2>3){continue;}
					res+=Solve(p-1,2*(r-i));
				}
				dp[p][r]=res;
				return res;
			}
        long long getNumber(long long N) 
            { 
#if 0
				this->num=N;
				memset(dp,-1,sizeof(dp));
				return Solve(63,0);
#else

				//the dp method
				for (int i=1;i<=3;i++){
					dp[0][i]=0;
				}
				dp[0][0]=1;
				for (int i=1;i<=64;i++){
					for (int j=0;j<=3;j++){
						int r=j;
						if (N>>(i-1) &1){
							r++;
						}
						dp[i][j]=0;
						for (int k=0;k<=2;k++){
							if (r-k<0){break;}
							if (2*(r-k)>3){continue;}
							dp[i][j]+=dp[i-1][2*(r-k)];
						}
					}
				}
				return dp[64][0];
#endif
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { long long Arg0 = 6LL; long long Arg1 = 3LL; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { long long Arg0 = 47LL; long long Arg1 = 2LL; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { long long Arg0 = 256LL; long long Arg1 = 9LL; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { long long Arg0 = 8489289LL; long long Arg1 = 6853LL; verify_case(4, Arg1, getNumber(Arg0)); }
	void test_case_5() { long long Arg0 = 1000000000LL; long long Arg1 = 73411LL; verify_case(5, Arg1, getNumber(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        TaroCoins ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

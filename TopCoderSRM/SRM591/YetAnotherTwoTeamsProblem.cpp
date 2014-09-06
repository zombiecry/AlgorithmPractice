// BEGIN CUT HERE 

// END CUT HERE
#line 5 "YetAnotherTwoTeamsProblem.cpp"
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
const int MAX_X =60000*50;
const int MAX_N =50;
class YetAnotherTwoTeamsProblem
        { 
        public: 
			vector<vector <long long>> dp;
			vector <int> A;
        long long count(vector <int> skill) 
            { 
				dp.resize(2);
				dp[0].resize(MAX_X+1);
				dp[1].resize(MAX_X+1);
				A=skill;
				n=skill.size();
				sort(A.begin(),A.end());
				int t=accumulate(A.begin(),A.end(),0);
				for (int i=0;i<=MAX_X;i++){
					if (i > t/2.0f){
						dp[1][i]=1;
					}
					else{
						dp[1][i]=0;
					}
				}
				for (int i=0;i<n;i++){
					int cur=i%2;
					int prev=(i-1)%2;
					if (i==0){
						prev=1;
					}
					for (int j=0;j<=MAX_X;j++){
						dp[cur][j]=dp[prev][j];
						if (j < t/2.0f){
							dp[cur][j]+=dp[prev][j+A[i]];
						}
					}
				}
				return dp[(n-1)%2][0];
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, 4, 7, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { int Arr0[] = {1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 10LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 5, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { int Arr0[] = {999, 999, 999, 1000, 1000, 1001, 999, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 999, 1000, 512, 511, 1001, 1001, 1001, 1001, 1001, 1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 17672631900LL; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        YetAnotherTwoTeamsProblem ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

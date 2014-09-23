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
        int countMinimums(int L) 
            { 
				memset(comb,-1,sizeof(comb));
				if (L<=26){
					long long res=1;
					for (int i=0;i<L;i++){
						res*=CalcC(26-i,1);
						res%=MODULAR;
					}
					return (int)res;
				}
				
				long long res=CalcC(26,L%26);
				for (int i=2;i<=26;i++){
					res *=i;
					res%=MODULAR;
				}
				return (int)res;
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
        ___test.run_test(2); 
        system("pause");
        } 
    // END CUT HERE 

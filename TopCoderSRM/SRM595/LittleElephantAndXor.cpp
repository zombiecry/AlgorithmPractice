// BEGIN CUT HERE 

// END CUT HERE
#line 5 "LittleElephantAndXor.cpp"
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
class LittleElephantAndXor
        { 
        public: 
			long long mem[2][2][2][33];
			long long Solve(int la,int lb,int lc,int p){
				if (mem[la][lb][lc][p]!=-1){return mem[la][lb][lc][p];}
				if (p == 32){
					mem[la][lb][lc][p]=1;
					return 1;
				}
				long long res=0;
				for (int i=0;i<=1;i++) for (int j=0;j<=1;j++){
					if (la==0 && A[p]==0 && i==1){continue;}
					if (lb==0 && B[p]==0 && j==1){continue;}
					int k=i ^ j;
					if (lc==0 && C[p]==0 && k==1){continue;}
					int nla=0,nlb=0,nlc=0;
					if (la == 1){nla=1;}
					else if (A[p]==1 && i==0){
						nla=1;
					}

					if (lb == 1){nlb=1;}
					else if (B[p]==1 && j==0){nlb=1;}

					if (lc == 1){nlc=1;}
					else if (C[p]==1 && k==0){nlc=1;}
					res +=Solve(nla,nlb,nlc,p+1);
				}
				mem[la][lb][lc][p]=res;
				return res;
			}
			vector <int> A;
			vector <int> B;
			vector <int> C;
        long long getNumber(int A, int B, int C) 
            { 
				this->A.resize(32);
				this->B.resize(32);
				this->C.resize(32);
				memset(mem,-1,sizeof(mem));
				for (int i=0;i<32;i++){
					int index=31-i;
					this->A[i]=(A>>index & 1);
					this->B[i]=(B>>index & 1);
					this->C[i]=(C>>index & 1);
				}
				return Solve(0,0,0,0);
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; long long Arg3 = 5LL; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 3; long long Arg3 = 20LL; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 5; long long Arg3 = 57LL; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 774; int Arg1 = 477; int Arg2 = 447; long long Arg3 = 214144LL; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1000000000; int Arg1 = 1000000000; int Arg2 = 500000000; long long Arg3 = 468566946385621507LL; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        LittleElephantAndXor ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

// BEGIN CUT HERE 

// END CUT HERE
#line 5 "GameOfSegments.cpp"
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

const int MAX_N = 1001;

int m,n;



class GameOfSegments
        { 
        public: 
			int mem[MAX_N];
		int Solve(int num){
			if (mem[num]!=-1){return mem[num];}
			if (num<2){
				mem[num]=0;
				return mem[num];
			}
			set <int> s;
			for (int i=0;i<((num-2)/2+1);i++){
				int g1=Solve(i);
				int g2=Solve(num-2-i);
				s.insert(g1 ^ g2);
			}
			int res=0;
			while(s.count(res)){res++;}
			mem[num]=res;
			return res;
		}
        int winner(int N) 
            { 
				n=n;
				memset(mem,-1,sizeof(mem));
				if (Solve(N)){
					return 1;
				}
				else{
					return 2;
				}
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; verify_case(0, Arg1, winner(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 1; verify_case(1, Arg1, winner(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 2; verify_case(2, Arg1, winner(Arg0)); }
	void test_case_3() { int Arg0 = 191; int Arg1 = 2; verify_case(3, Arg1, winner(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        GameOfSegments ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

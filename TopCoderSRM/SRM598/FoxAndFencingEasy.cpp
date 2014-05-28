// BEGIN CUT HERE 

// END CUT HERE
#line 5 "FoxAndFencingEasy.cpp"
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

typedef long long int scLLi;
typedef long long unsigned int scLLui;
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

int m,n;
class FoxAndFencingEasy
        { 
        public: 
        string WhoCanWin(int mov1, int mov2, int d) 
            { 
				string w1s="Ciel";
				string w2s="Liss";
				string equs="Draw";
				if (d<=mov1){
					return w1s;
				}
				if (mov1>2*mov2){
					return w1s;
				}
				if (mov2>2*mov1){
					return w2s;
				}
				return equs;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 58; int Arg2 = 1; string Arg3 = "Ciel"; verify_case(0, Arg3, WhoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arg1 = 100; int Arg2 = 100000000; string Arg3 = "Draw"; verify_case(1, Arg3, WhoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 150; int Arg2 = 100000000; string Arg3 = "Draw"; verify_case(2, Arg3, WhoCanWin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 250; int Arg2 = 100000000; string Arg3 = "Liss"; verify_case(3, Arg3, WhoCanWin(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        FoxAndFencingEasy ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

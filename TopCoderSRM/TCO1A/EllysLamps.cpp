// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysLamps.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair


int n,m;
class EllysLamps
{
        public:
        int getMin(string lamps)
        {
            n=lamps.length();
			for (int i=0;i<n;i++){

			}
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "YNNYN"; int Arg1 = 2; verify_case(0, Arg1, getMin(Arg0)); }
	void test_case_1() { string Arg0 = "NNN"; int Arg1 = 0; verify_case(1, Arg1, getMin(Arg0)); }
	void test_case_2() { string Arg0 = "YY"; int Arg1 = 0; verify_case(2, Arg1, getMin(Arg0)); }
	void test_case_3() { string Arg0 = "YNYYYNNNY"; int Arg1 = 3; verify_case(3, Arg1, getMin(Arg0)); }
	void test_case_4() { string Arg0 = "YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY"; int Arg1 = 13; verify_case(4, Arg1, getMin(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        EllysLamps ___test;
        ___test.run_test(-1);
        system("pause");
        return 0;
}
// END CUT HERE

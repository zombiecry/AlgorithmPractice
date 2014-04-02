// BEGIN CUT HERE

// END CUT HERE
#line 5 "TorusSailingEasy.cpp"
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
class TorusSailingEasy
{
        public:
        double expectedTime(int N, int M, int goalX, int goalY)
        {
            int i=1;
			int curX=0;
			int curY=0;
			double x=-1;
			while(true){
				curX=(i)%N;
				curY=(i)%M;
				if (curX==0 &&curY==0){
					break;
				}
				if (curX==goalX && curY==goalY){
					x=i;
				}
				i++;
			}
			if (x<0){
				return -1.0;
			}
			double y=i-x;
			double possi1=2*x/(pow(2,x));
			double possi2=2*y/(pow(2,y));
			return possi1+possi2;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; double Arg4 = 1.0; verify_case(0, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 1; double Arg4 = -1.0; verify_case(1, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; double Arg4 = 2.0; verify_case(2, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 1; int Arg3 = 3; double Arg4 = 27.0; verify_case(3, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        TorusSailingEasy ___test;
        //___test.run_test(-1);
		___test.run_test(0);
        system("pause");
        return 0;
}
// END CUT HERE

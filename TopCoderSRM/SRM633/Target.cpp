// BEGIN CUT HERE

// END CUT HERE
#line 5 "Target.cpp"
#include <vector>
#include <list>
#include <bitset>
#include <map>
#include <set>
#include <deque>
#include <queue>
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



int n,m;
class Target
{
        public:
		vector <string> c;

		void Draw(int sx,int sy,int l){
			for (int i=0;i<l;i++){
				int x=sx+i;
				int y0=sy;
				int y1=sy+l-1;
				c[y0][x]='#';
				c[y1][x]='#';
			}

			for (int i=0;i<l;i++){
				int x0=sx;
				int x1=sx+l-1;
				int y=sy+i;
				c[y][x0]='#';
				c[y][x1]='#';
			}
		}

        vector <string> draw(int n)
        {
            
			c.resize(n);
			for (int i=0;i<n;i++){
				c[i].resize(n,' ');
			}
			m=n/4+1;
			for (int i=0;i<m;i++){
				Draw(n/2 - i*2,n/2 - i*2,4*i+1);
			}
			return c;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"#####", "#   #", "# # #", "#   #", "#####" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, draw(Arg0)); }
	void test_case_1() { int Arg0 = 9; string Arr1[] = {"#########", "#       #", "# ##### #", "# #   # #", "# # # # #", "# #   # #", "# ##### #", "#       #", "#########" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, draw(Arg0)); }
	void test_case_2() { int Arg0 = 13; string Arr1[] = {"#############", "#           #", "# ######### #", "# #       # #", "# # ##### # #", "# # #   # # #", "# # # # # # #", "# # #   # # #", "# # ##### # #", "# #       # #", "# ######### #", "#           #", "#############" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, draw(Arg0)); }
	void test_case_3() { int Arg0 = 17; string Arr1[] = {"#################", "#               #", "# ############# #", "# #           # #", "# # ######### # #", "# # #       # # #", "# # # ##### # # #", "# # # #   # # # #", "# # # # # # # # #", "# # # #   # # # #", "# # # ##### # # #", "# # #       # # #", "# # ######### # #", "# #           # #", "# ############# #", "#               #", "#################" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, draw(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        Target ___test;
        ___test.run_test(4);
        system("pause");
        return 0;
}
// END CUT HERE

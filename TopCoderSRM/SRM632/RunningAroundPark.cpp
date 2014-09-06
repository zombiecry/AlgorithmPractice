// BEGIN CUT HERE 

// END CUT HERE
#line 5 "RunningAroundPark.cpp"
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
class RunningAroundPark
        { 
        public: 
        int numberOfLap(int N, vector <int> d) 
            { 
				n=d.size();
				int res=1;
				for (int i=1;i<n;i++){
					if (d[i] <= d[i-1]){
						res++;
					}
				}
				return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, numberOfLap(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 24; int Arr1[] = {6,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(1, Arg2, numberOfLap(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arr1[] = {3,2,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, numberOfLap(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 50; int Arr1[] = {1,3,5,7,9,2,4,6,8,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(3, Arg2, numberOfLap(Arg0, Arg1)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        RunningAroundPark ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

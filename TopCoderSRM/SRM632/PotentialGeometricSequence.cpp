// BEGIN CUT HERE 

// END CUT HERE
#line 5 "PotentialGeometricSequence.cpp"
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
class PotentialGeometricSequence
        { 
        public: 
			vector <int> d;
			bool Check(int p,int q){
				if (p==q){return true;}
				int delta=d[p+1]-d[p];
				for (int i=p+2;i<=q;i++){
					int curD=d[i]-d[i-1];
					if (curD!=delta){
						return false;
					}
				}
				return true;
			}
        int numberOfSubsequences(vector <int> d) 
            { 
				int res=0;
				this->d=d;
				n=d.size();
				for (int i=0;i<n;i++){
					for (int j=i;j<n;j++){
						if (Check(i,j)){
							res++;
						}
					}
				}
				return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_2() { int Arr0[] = {3,2,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,4,8,16}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_4() { int Arr0[] = {1,3,5,5,5,5,64,4,23,2,3,4,5,4,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 37; verify_case(4, Arg1, numberOfSubsequences(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        PotentialGeometricSequence ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

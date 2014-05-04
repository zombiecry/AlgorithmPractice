// BEGIN CUT HERE 

// END CUT HERE
#line 5 "MyVeryLongCake.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#define tr(container,it)    \
    for (it=container.begin();it!=container.end();it++)
typedef std::pair <int,int> scPair2i;

class MyVeryLongCake
        { 
	public:
        int cut(int n)  
		{  
			set <int> divs; 
			vector <int> dd(n+1,0); 
			double sq = sqrt(double(n)); 
			int m = (int)floor(sq); 
			m=min(m,n-1); 
			for (int i=1;i<=m;i++){ 
				if (n%i ==0){ 
					int d=n/i; 
					for (int j=0;j<=n;j+=d){ 
						//divs.insert(j); 
						dd[j]=1; 
					} 
					d=i; 
					if (d>1){ 
						for (int j=0;j<=n;j+=d){ 
							//divs.insert(j); 
							dd[j]=1; 
						} 
					} 
				} 
			} 
			int sum=-1; 
			for (int i=0;i<n+1;i++){ 
				if (dd[i]){ 
					sum++; 
				} 
			} 
			return sum; 
		}  


        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 4; verify_case(0, Arg1, cut(Arg0)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; verify_case(1, Arg1, cut(Arg0)); }
	void test_case_2() { int Arg0 = 15; int Arg1 = 7; verify_case(2, Arg1, cut(Arg0)); }
	void test_case_3() { int Arg0 = 1000000000; int Arg1 = 600000000; verify_case(3, Arg1, cut(Arg0)); }
	void test_case_4() { int Arg0 = 577007436; int Arg1 = 384671628; verify_case(4, Arg1, cut(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        MyVeryLongCake ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

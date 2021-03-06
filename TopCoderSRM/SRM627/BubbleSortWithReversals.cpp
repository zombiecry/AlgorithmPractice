// BEGIN CUT HERE 

// END CUT HERE
#line 5 "BubbleSortWithReversals.cpp"
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
class BubbleSortWithReversals
        { 
        public: 
			vector <int> A;
			int    c[51][51];
			int Count(vector <int> &B,int x){
				int res=0;
				for (;x<(int)B.size();x++){
					for (int i=0;i<x;i++){
						if (B[i]>B[x]){
							res++;
						}
					}
				}
				return res;
			}
			int Solve(int p,int k){
				if (p>=n){
					c[p][k]=0;
					return 0;
				}
				if (c[p][k]!=-1){
					return c[p][k];
				}
				vector <int> B(A.begin(),A.begin()+p+1);
				int res=Solve(p+1,k)+Count(B,p);
				if (k>0){
					for (int i=p+1;i<n;i++){
						vector <int> B(A.begin(),A.begin()+i+1);
						reverse(B.begin()+p,B.begin()+i+1);
						res=min(res,Count(B,p)+Solve(i+1,k-1));
					}
				}
				c[p][k]=res;
				return res;
			}
        int getMinSwaps(vector <int> A, int K) 
            { 
				this->A=A;
				n=A.size();
				memset(c,-1,sizeof(c));
				return Solve(0,K);
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,8,8,7,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(0, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {7,2,2,13,5,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {12,5,1,10,12,6,6,10,6,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 12; verify_case(2, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,3,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 1; verify_case(3, Arg2, getMinSwaps(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {482,619,619,601,660,660,691,691,77,77,96,77}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; int Arg2 = 22; verify_case(4, Arg2, getMinSwaps(Arg0, Arg1)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        BubbleSortWithReversals ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

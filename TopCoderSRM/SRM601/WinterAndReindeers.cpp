// BEGIN CUT HERE 

// END CUT HERE
#line 5 "WinterAndReindeers.cpp"
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
int    dp[2502][2502][2];
int    eA[2502];
int    eB[2502];
class WinterAndReindeers
        { 
        public: 
			string A;
			string B;
			string C;
		void CalcE(string &s,int *es){
			scFor0(i,s.length()){
				es[i]=-1;
				int k=0;
				scFor1(j,i,s.length()){
					if (s[j]==C[k]){
						k++;
						if (k==C.length()){
							es[i]=j+1;
							break;
						}
					}
				}
			}
		}

		int Solve(int p,int q,int s){
			if (dp[p][q][s]!=-1){
				return dp[p][q][s];
			}
			if (s==0){
				if (p==A.length() || q==B.length()){
					dp[p][q][s]=-2;
					return -2;
				}
				int res=-2;
				if (eA[p]!=-1 && eB[q]!=-1){
					res=max(res,(int)C.length()+Solve(eA[p],eB[q],1));
					if (A[p]==B[q]){
						res=max(res,Solve(p+1,q+1,s)+1);
					}
					res=max(res,Solve(p,q+1,s));
					res=max(res,Solve(p+1,q,s));
				}
				dp[p][q][s]=res;
				return res;
			}
			if (s==1){
				if (p==A.length() || q==B.length()){
					dp[p][q][s]=0;
					return 0;
				}
				int res=0;
				if (A[p]==B[q]){
					res=Solve(p+1,q+1,s)+1;
				}
				res=max(res,Solve(p+1,q,s));
				res=max(res,Solve(p,q+1,s));
				dp[p][q][s]=res;
				return res;
			}
			return -2;
		}
        int getNumber(vector <string> allA, vector <string> allB, vector <string> allC) 
            { 
				A.clear();
				B.clear();
				C.clear();
				scFor0(i,allA.size()){
					scFor0(j,allA[i].length()){
						A+=allA[i][j];
					}
				}
				scFor0(i,allB.size()){
					scFor0(j,allB[i].length()){
						B+=allB[i][j];
					}
				}
				scFor0(i,allC.size()){
					scFor0(j,allC[i].length()){
						C+=allC[i][j];
					}
				}
				memset(dp,-1,sizeof(dp));
				CalcE(A,eA);
				CalcE(B,eB);
				int res=Solve(0,0,0);
				if (res<0){
					return 0;
				}
				return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"X", "Y"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"X"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"ABCXD"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"BCDEF"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"CD"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"WE", "LOVE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"WORKING", "FOR", "SANTA"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"JK"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"ABCDE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"CDEAB"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"B"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"AXBADXBBAB", "CDD"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 23; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        WinterAndReindeers ___test; 
        ___test.run_test(4); 
        system("pause");
        } 
    // END CUT HERE 

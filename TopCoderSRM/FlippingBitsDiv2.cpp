// BEGIN CUT HERE 

// END CUT HERE
#line 5 "FlippingBitsDiv2.cpp"
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
class FlippingBitsDiv2
        { 
        public: 
			vector <int> sm;
			vector <int> em;
			vector <char> A;
        int getmin(vector <string> S, int M) 
            { 
				for (int i=0;i<S.size();i++) for (int j=0;j<S[i].length();j++){
					A.push_back(S[i][j]-'0');
				}
				n=A.size();
				int n0=0;
				int n1=0;
				sm.resize(n);
				em.resize(n);
				for (int i=0;i<n;i++){
					if (A[i]==0){n0++;}
					else {n1++;}
					sm[i]=min(n0,n1+1);
				}
				n0=0;
				n1=0;
				for (int i=n-1;i>=0;i--){
					if (A[i]==0){n0++;}
					else {n1++;}
					em[i]=min(n0,n1+1);
				}
				int ans=numeric_limits<int>::max();
				for (int i=0;i<=n;i+=M){
					int p=i-1;
					for (int j=0;j+i<n+M;j+=M){
						int q=n-j;
						//clac config of p,q
						int cur=0;
						if (p>=q){
							int np=min(p,q);
							int nq=max(p,q);
							if (np-1>=0){cur+=sm[np-1];}
							if (nq+1<n){cur+=em[nq+1];}
							for (int k=p;k<=q;k++){
								if (A[k]==0){cur++;}
							}
						}
						else {	//p<q
							if (p>=0){cur+=sm[p];}
							if (q<n){cur+=em[q];}
							for (int k=p+1;k<q;k++){
								if (A[k]==0){cur++;}
							}
						}
						ans=min(ans,cur);
					}
				}
				return ans;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"00111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, getmin(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"00111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getmin(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, getmin(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"00100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 2; verify_case(3, Arg2, getmin(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"00010","11010110","1010111","110001010","0110001100"
,"000110110","011010101","00","111","100"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 31; verify_case(4, Arg2, getmin(Arg0, Arg1)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        FlippingBitsDiv2 ___test; 
        ___test.run_test(4); 
        system("pause");
        } 
    // END CUT HERE 

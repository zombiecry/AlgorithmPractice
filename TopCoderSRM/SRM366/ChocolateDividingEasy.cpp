// BEGIN CUT HERE 

// END CUT HERE
#line 5 "ChocolateDividingEasy.cpp"
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
class ChocolateDividingEasy
        { 
        public: 
        int findBest(vector <string> chocolate) 
            { 
				vector <string> &cho=chocolate;
				n=cho.size();
				m=cho[0].size();
				//pre-table
				vector<vector<int>> at(n+1,vector<int>(m+1,0));
				for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
					at[i][j]=(cho[i-1][j-1]-'0')+at[i-1][j]+at[i][j-1]-at[i-1][j-1];
				}
				int res=0;
				for(int x0=1;x0<n-1;x0++) for(int x1=x0+1;x1<n;x1++) {
					for(int y0=1;y0<m-1;y0++) for(int y1=y0+1;y1<m;y1++){
						vector<vector<int>> a(3,vector<int>(3,0));
						int cx[4];
						int cy[4];
						cx[0]=0;cx[1]=x0;cx[2]=x1;cx[3]=n;
						cy[0]=0;cy[1]=y0;cy[2]=y1;cy[3]=m;
						int minv=numeric_limits<int>::max();
						for(int i=1;i<=3;i++) for(int j=1;j<=3;j++){
							minv=min(minv,at[cx[i]][cy[j]]-at[cx[i-1]][cy[j]]-at[cx[i]][cy[j-1]]+at[cx[i-1]][cy[j-1]]);
						}
						res=max(res,minv);
					}
				}
				return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"9768",
"6767",
"5313"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, findBest(Arg0)); }
	void test_case_1() { string Arr0[] = {
"36753562",
"91270936",
"06261879",
"20237592",
"28973612",
"93194784"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 15; verify_case(1, Arg1, findBest(Arg0)); }
	void test_case_2() { string Arr0[] = {
"012",
"345",
"678"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, findBest(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        ChocolateDividingEasy ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

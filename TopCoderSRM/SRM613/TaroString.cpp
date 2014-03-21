// BEGIN CUT HERE

// END CUT HERE
#line 5 "TaroString.cpp"
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
class TaroString
{
        public:
        string getAnswer(string S)
        {
            int a[26];
			memset(a,0,sizeof(int)*26);
			for (int i=0;i<S.length();i++){
				a[S[i]-'A']=1;
			}
			string str2Find="CAT";
			for (int i=0;i<26;i++){
				if (a[i]){
					char x=i+'A';
					if (x=='C' ||
						x=='A' ||
						x=='T'){
							continue;
					}
					string curStr="";
					for (int j=0;j<S.length();j++){
						if (S[j]!=x){
							curStr+=S[j];
						}
					}
					S=curStr;
				}
			}
			if (S==str2Find){
				return "Possible";
			}
			return "Impossible";
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "XCYAZTX"; string Arg1 = "Possible"; verify_case(0, Arg1, getAnswer(Arg0)); }
	void test_case_1() { string Arg0 = "CTA"; string Arg1 = "Impossible"; verify_case(1, Arg1, getAnswer(Arg0)); }
	void test_case_2() { string Arg0 = "ACBBAT"; string Arg1 = "Impossible"; verify_case(2, Arg1, getAnswer(Arg0)); }
	void test_case_3() { string Arg0 = "SGHDJHFIOPUFUHCHIOJBHAUINUIT"; string Arg1 = "Possible"; verify_case(3, Arg1, getAnswer(Arg0)); }
	void test_case_4() { string Arg0 = "CCCATT"; string Arg1 = "Impossible"; verify_case(4, Arg1, getAnswer(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        TaroString ___test;
        ___test.run_test(-1);
        system("pause");
        return 0;
}
// END CUT HERE

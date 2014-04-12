// BEGIN CUT HERE 

// END CUT HERE
#line 5 "MergeStrings.cpp"
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
#ifdef __GNUC__
#define tr(container, it) \
	for (typeof(container.begin()) it = container.begin(); it != container.end();it++)

#define trCheck(container, it) \
	for (typeof(container.begin()) it = container.begin(); it != container.end();)

#else
#ifdef _MSC_VER
#define tr(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();it++)
#define trCheck(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();)

#endif
#endif
typedef std::pair <int,int> scPair2i;

class MergeStrings
        { 
        public: 
		bool Match(char ch1,char ch2){
			if (ch1=='?'){
				return true;
			}
			return ch1==ch2;
		}


		bool Match(string s1,string s2){
			for (int i=0;i<s1.length();i++){
				if (!Match(s1[i],s2[i])){
					return false;
				}
			}
			return true;
		}
        string getmin(string S, string A, string B) 
            { 
				int n=S.length();
				int m1=A.length();
				int m2=B.length();
				string c[50][50];
				for (int i=0;i<m1;i++){
					string sLeft=S.substr(i+m2);
					string aLeft=A.substr(i);
					if (Match(sLeft,aLeft)){
						c[i][m2]=aLeft;
					}
				}

				for (int i=0;i<m2;i++){
					string sLeft=S.substr(i+m1);
					string bLeft=B.substr(i);
					if (Match(sLeft,bLeft)){
						c[m1][i]=bLeft;
					}
				}


				for (int i=m1-1;i>=0;i--){
					for (int j=m2-1;j>=0;j--){
						string s1="";
						string s2="";
						if (c[i+1][j].length()>0){
							if (Match(S[i+j],A[i])){
								s1=A[i]+c[i+1][j];
							}
						}
						if (c[i][j+1].length()>0){
							if (Match(S[i+j],B[j])){
								s2=B[j]+c[i][j+1];
							}
						}
						if (s1.length()>0 && s2.length()>0){
							c[i][j]=min(s1,s2);
						}
						else{
							if (s1.length()>0){
								c[i][j]=s1;
							}
							if (s2.length()>0){
								c[i][j]=s2;
							}
						}

					}
				}
				return c[0][0];
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "??CC??"; string Arg1 = "ABC"; string Arg2 = "BCC"; string Arg3 = "ABCCBC"; verify_case(0, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "WHAT?"; string Arg1 = "THE"; string Arg2 = "WA"; string Arg3 = ""; verify_case(1, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "PARROT"; string Arg1 = "PARROT"; string Arg2 = ""; string Arg3 = "PARROT"; verify_case(2, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "???????????"; string Arg1 = "AZZAA"; string Arg2 = "AZAZZA"; string Arg3 = "AAZAZZAAZZA"; verify_case(3, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "????K??????????????D???K???K????????K?????K???????"; string Arg1 = "KKKKKDKKKDKKDDKDDDKDKK"; string Arg2 = "KDKDDKKKDDKDDKKKDKDKKDDDDDDD"; string Arg3 = "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK"; verify_case(4, Arg3, getmin(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        MergeStrings ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

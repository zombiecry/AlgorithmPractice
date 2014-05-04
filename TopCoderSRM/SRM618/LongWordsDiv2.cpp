// BEGIN CUT HERE 

// END CUT HERE
#line 5 "LongWordsDiv2.cpp"
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
int n;
class LongWordsDiv2
        { 
        public: 
		bool CheckCons(const string &A){
			for (int i=0;i<n-1;i++){
				if (A[i]==A[i+1]){
					return true;
				}
			}
			return false;
		}
		bool CheckXY(const string &A){
			for (int i=0;i<=n-4;i++){
				char x1=A[i];
				for (int j=i+1;j<=n-3;j++){
					char y1=A[j];
					for (int k=j+1;k<=n-2;k++){
						char x2=A[k];
						if (x1!=x2){
							continue;
						}
						for (int l=k+1;l<=n-1;l++){
							char y2=A[l];
							if (y1==y2){
								return true;
							}
						}
					}
				}
			}
			return false;
		}
        string find(string word) 
            { 
				string likeStr="Likes";
				string dislikeStr="Dislikes";
				n=word.length();
				if (CheckCons(word)){
					return dislikeStr;
				}
				if (CheckXY(word)){
					return dislikeStr;
				}
				return likeStr;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AAA"; string Arg1 = "Dislikes"; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { string Arg0 = "ABCBA"; string Arg1 = "Likes"; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { string Arg0 = "ABCBAC"; string Arg1 = "Dislikes"; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { string Arg0 = "TOPCODER"; string Arg1 = "Likes"; verify_case(3, Arg1, find(Arg0)); }
	void test_case_4() { string Arg0 = "VAMOSGIMNASIA"; string Arg1 = "Dislikes"; verify_case(4, Arg1, find(Arg0)); }
	void test_case_5() { string Arg0 = "SINGLEROUNDMATCH"; string Arg1 = "Likes"; verify_case(5, Arg1, find(Arg0)); }
	void test_case_6() { string Arg0 = "DALELOBO"; string Arg1 = "Likes"; verify_case(6, Arg1, find(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        LongWordsDiv2 ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

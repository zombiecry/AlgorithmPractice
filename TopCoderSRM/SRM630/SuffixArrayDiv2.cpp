// BEGIN CUT HERE 

// END CUT HERE
#line 5 "SuffixArrayDiv2.cpp"
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
typedef pair <string,int> scPair;
class SuffixArrayDiv2
        { 
        public: 
			//suffix rank array
			vector <int> A;
			//B[i] means the rank in A of the suffix from index i
			//which is an reverse of A's index-value
			vector <int> B;
			string smallerOne(string s) {
				n=s.length();
				//use set for sorting suffix index based suffix
				set <scPair> surf; 
				for (int i=0;i<n;i++){
					surf.insert(scPair(s.substr(i),i));
				}
				set<scPair> ::iterator it=surf.begin();
				A.resize(n);
				B.resize(n+1);
				int count=0;
				for (;it!=surf.end();it++){
					A[count]=it->second;
					B[it->second]=count;
					count++;
				}
				//--------------------------------
				//since B[ai+1] would exceed n, assum the empty suffix be a smallest one
				B[n]=-1;		
				string res;
				res.resize(n);
				char cur='a';
				res[A[0]]=cur;
				//the least possible string
				for (int i=1;i<n;i++){
					if (B[A[i-1]+1] >= B[A[i]+1]){
						cur++;
					}
					res[A[i]]=cur;
				}
				if (res < s){
					return "Exists";
				}
				else{
					return "Does not exist";
				}
			}
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "abca"; string Arg1 = "Exists"; verify_case(0, Arg1, smallerOne(Arg0)); }
	void test_case_1() { string Arg0 = "bbbb"; string Arg1 = "Exists"; verify_case(1, Arg1, smallerOne(Arg0)); }
	void test_case_2() { string Arg0 = "aaaa"; string Arg1 = "Does not exist"; verify_case(2, Arg1, smallerOne(Arg0)); }
	void test_case_3() { string Arg0 = "examplesareveryweakthinktwicebeforesubmit"; string Arg1 = "Exists"; verify_case(3, Arg1, smallerOne(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        SuffixArrayDiv2 ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

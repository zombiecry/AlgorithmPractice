// BEGIN CUT HERE 

// END CUT HERE
#line 5 "PotentialArithmeticSequence.cpp"
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
class PotentialArithmeticSequence
        { 
        public: 
			vector<int> d;
			int CalcD(int step){	
				int num=0;
				for(int i=0;i<step;i++){
					num+=2;
				}
				int res=0;
				while(!(num & 1)){
					res++;
					num=num>>1;
				}
				return res;
			}
			bool Check(int p,int q){
				for(int i=p;i<q;i++){
					if (i<q-1) {
						if (!d[i] && !d[i+1]) return false;
						if (d[i] && d[i+1]) return false;
					}
					if (d[i]==0) continue;
					for(int j=i+2;j<q;j+=2){
						if (d[j]==0) return false;
						int k=(j-i)/2;
						int d2k=CalcD(k);
						if (d[i]>d2k) {
							if (d[j]!=d2k) return false;
						}
						else if (d[i]<d2k){
							if (d[j]!=d[i]) return false;
						}
						else{	//di==d2k
							if (d[j]<=d2k) return false;
						}
					}
				}
				return true;
			}
        int numberOfSubsequences(vector <int> d) 
            { 
				this->d=d;
				n=d.size();
				int res=0;
				for(int i=0;i<n;i++) {
					for(int j=i+1;j<=n;j++){
						if (Check(i,j)) {
							res++;
						}
					}
				}
				return res;
            //$CARETPOSITION$ 
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,0,2,0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(0, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,0,0,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(2, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_3() { int Arr0[] = {0,100,0,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 11; verify_case(3, Arg1, numberOfSubsequences(Arg0)); }
	void test_case_4() { int Arr0[] = {1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 49; verify_case(4, Arg1, numberOfSubsequences(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        PotentialArithmeticSequence ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

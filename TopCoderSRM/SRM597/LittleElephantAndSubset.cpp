// BEGIN CUT HERE 

// END CUT HERE
#line 5 "LittleElephantAndSubset.cpp"
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

const long long MODULAR = 1000000007 ;
int m,n;
class LittleElephantAndSubset
        { 
        public: 
			int    pre[1<<11];	
			int CalcPre(int A){
				vector <int> s;
				for (int i=0;i<10;i++){
					if ((A >> i) & 1){
						s.push_back(i);
					}
				}
				long long res=0;
				do{
					if (s[0]==0){continue;}
					long long dig=1;
					long long num=0;
					for (int i=s.size()-1;i>=0;i--){
						num+=s[i]*dig;
						dig*=10;
						if (num > n){
							break;
						}
					}
					if (num <= n){
						res++;
						res %= MODULAR;
					}
					else{
						break;
					}
				}while(next_permutation(s.begin(),s.end()));
				return res;
			}
		int Calc (int par[]){
			long long res=1;
			for (int i=0;i<11;i++){
				if (par[i]){
					int num=par[i] << i;
					res *= pre[num];
					res %= MODULAR;
					if (res ==0){
						break;
					}
				}
			}
			return res;
		}
		int par[11];
		int Solve(int a,int p){
			if (p<10){
				long long res=0;
				if ((a >> p) & 1){
					par[p]=0;
					res = Solve(a, p+1);
				}
				else{
					for (int i=0;i < (1 << (10-p)) ; i++){
						int a1 = a >> (p+1);
						if ((a1 & i) == 0){
							int a2 = a | (i << (p+1));
							a2 |= 1<<p;
							par[p] = (i << 1) | 1;
							res += Solve(a2 , p+1);
							res %= MODULAR;
						}
					}
				}
				return res;
			}
			else {
				if ((a >> p) & 1 ){
					par[p]=0;
				}
				else{
					par[p]=1;
				}
				int res=Calc(par);
				return res;
			}
		}
        int getNumber(int N) 
            { 
				n=N;
				//pre calc 
				for (int i=1;i < 1 << 11 ;i++){
					if ((i & 1) ==1 ){
						pre[i]=1;
						continue;
					}
					pre[i]=CalcPre(i>>1);
				}
				return Solve(0,0)-1;
		} 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 7; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 767; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { int Arg0 = 47; int Arg1 = 25775; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { int Arg0 = 4777447; int Arg1 = 66437071; verify_case(3, Arg1, getNumber(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        LittleElephantAndSubset ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

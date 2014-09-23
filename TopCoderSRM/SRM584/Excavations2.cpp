// BEGIN CUT HERE 

// END CUT HERE
#line 5 "Excavations2.cpp"
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
class Excavations2
        { 
        public: 
			vector <int> km;
			vector <bool> fm;
			int K;
			long long dp[51][51];
			long long comb[51][51];
			long long Solve(int t,int k){
				if (t==-1){			//left none types
					if (k==0){return 1;}
					return 0;
				}
				if (k==0){//non-discovered cities,but left some types unassigned
					if (fm[t]){return 0;}
				}
				if (dp[t][k]!=-1){return dp[t][k];}
				long long res=0;
				if (!fm[t]){	//type t not discovered. k belongs to [0,t-1] types
					res=Solve(t-1,k);
				}
				else{
					int maxt=min(km[t],k);	//the limit make k>=0
					for (int i=1;i<=maxt;i++){
						//select i cities from km[t] cites
						res+=(Comb(km[t],i)*Solve(t-1,k-i));
					}
				}
				dp[t][k]=res;
				return res;
			}

			long long Comb(int a,int b){
				if (a==0){
					if (b==0){return 1;}	//select 0 from 0
					return 0;	//select b>0 from 0 elements: no way
				}
				if (b==0){	//a!=0
					return 1;	//select 0 elements
				}
				if (comb[a][b]!=-1){return comb[a][b];}
				long long res=Comb(a-1,b-1)+Comb(a-1,b);
				comb[a][b]=res;
				return res;
			}
        long long count(vector <int> kind, vector <int> found, int K) 
            { 
				m=kind.size();
				int n=*max_element(kind.begin(),kind.end());
				km.resize(n,0);		//type i has km[i] cities
				for (int i=0;i<m;i++){
					km[kind[i]-1]++;
				}
				fm.resize(n,false);	//fm[i]: type i has been found
				for (int i=0;i<found.size();i++){
					fm[found[i]-1]=true;
				}
				this->K=K;
				memset(dp,-1,sizeof(dp));
				memset(comb,-1,sizeof(comb));
				return Solve(n-1,K);
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 1LL; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 2, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 4LL; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1, 2, 1, 1, 2, 3, 4, 3, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; long long Arg3 = 6LL; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 21; long long Arg3 = 5567902560LL; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        Excavations2 ___test; 
		___test.run_test(3); 
		system("pause");
        } 
    // END CUT HERE 

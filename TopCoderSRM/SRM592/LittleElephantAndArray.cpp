// BEGIN CUT HERE 

// END CUT HERE
#line 5 "LittleElephantAndArray.cpp"
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
const int MAX_N = 1<<16;
const int MODULAR = 1000000007;
class LittleElephantAndArray
        { 
        public: 
			//dp only use recursion with dp[i-1][?] and dp[i][j-1]
			//so only two array is enough
			int dp[2][MAX_N+1];
        int getNumber(long long A, int N) 
            { 
				 //dp[-1][j]=1
				 //since we have no number to consider, only one way
				 for (int i=0;i<=MAX_N;i++){
					 dp[1][i]=1;
				 }
				 //x[i][:] is an array, which saved all possible combine after
				 //removing some digits from A+i
				 vector <long long>  x[2];
				 x[1].push_back(-1);
				 for (int i=0;i<=N;i++){
					 int cur=i%2;
					 int prev=i-1;
					 if (prev<0){
						 prev=1;
					 }
					 else{
						 prev%=2;
					 }
					 string ns=to_string(A+i);
					 reverse(ns.begin(),ns.end());
					 m=ns.length();
					 x[cur].resize(0);
					 for (int j=1;j <1<<m ;j++){
						 long long num=0;
						 long long dig=1;
						 for (int k=0;k<m;k++){
							 if (j & (1<<k)){
								 num+= dig *(ns[k]-'0');
								 dig*=10;
							 }
						 }
						 
						 x[cur].push_back(num);
					 }
					 sort(x[cur].begin(),x[cur].end());
					 m=x[cur].size();
					 //recursion with: dp[p][k]=dp[p-1][j]+dp[p][k-1]
					 //j is calculated from p-1's possibilities.
					 for (int k=0;k<m;k++){
						 dp[cur][k]=0;
						 if (k>0){
							 dp[cur][k]=dp[cur][k-1];
						 }

						 if (x[cur][k]>=x[prev][0]){
							 int j=upper_bound(x[prev].begin(),x[prev].end(),x[cur][k])-x[prev].begin()-1;
							 long long temp=dp[prev][j]+dp[cur][k];
							 temp%=MODULAR;
							 dp[cur][k]=(int)temp;
						 }
					 }
					 
				 }
				 return dp[N%2][x[N%2].size()-1];
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; int Arg1 = 9; int Arg2 = 1; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 10LL; int Arg1 = 2; int Arg2 = 15; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 4747774LL; int Arg1 = 1; int Arg2 = 8369; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 6878542150015LL; int Arg1 = 74; int Arg2 = 977836619; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        LittleElephantAndArray ___test; 
        ___test.run_test(3); 
        system("pause");
        } 
    // END CUT HERE 

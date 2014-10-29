// BEGIN CUT HERE

// END CUT HERE
#line 5 "GreaterGame.cpp"
#include <vector>
#include <list>
#include <bitset>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
const int MAX_N=50;
int n,m;
class GreaterGame
{
        public:
		vector<int> h;
		vector<int> so;
		vector<bool> som;
		vector<bool> sum;
        double calc(vector <int> hand, vector <int> sothe)
        {
            h=hand;so=sothe;
			n=h.size();
			som.resize(MAX_N*2+1,0);
			sum.resize(MAX_N*2+1,0);
			for(int i=0;i<n;i++){
				sum[h[i]-1]=1;
			}
			for(int i=0;i<2*n;i++){
				if(!sum[i]) som[i]=1;
			}
			int mustWin=0;
			int known=0;
			for(int i=0;i<n;i++){
				if(so[i]!=-1){
					known++;
					int sun=so[i]-1;
					bool found=false;
					som[sun]=false;
					for(int j=sun+1;j<2*n;j++){
						if (sum[j]) {
							sum[j]=false;
							mustWin++;
							found=true;
							break;
						}
					}
					if (!found){
						for(int j=0;j<2*n;j++){
							if (sum[j]) {
								sum[j]=false;
								break;
							}
						}
					}
				}
			}
			int x=0,y=0;
			for(int i=0;i<2*n;i++) for(int j=0;j<2*n;j++){
				if (sum[i] &&som[j]){
					if (i>j) x++;
					y++;
				}
			}
			if ((n-known)==0) return mustWin;
			return (double(x)/double(y))*(n-known)+mustWin;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.5; verify_case(0, Arg2, calc(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.0; verify_case(1, Arg2, calc(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 1.0; verify_case(2, Arg2, calc(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1,3,5,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {8,-1,4,-1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 2.5; verify_case(3, Arg2, calc(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {6,12,17,14,20,8,16,7,2,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-1,-1,4,-1,11,3,13,-1,-1,18}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 8.0; verify_case(4, Arg2, calc(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        GreaterGame ___test;
        ___test.run_test(4);
        system("pause");
        return 0;
}
// END CUT HERE

// BEGIN CUT HERE

// END CUT HERE
#line 5 "MinimumSquareEasy.cpp"
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
class MinimumSquareEasy
{
        public:
        long long minArea(vector <int> x, vector <int> y)
        {
            int n=x.size();
			std::vector <bool> flags;

			flags.resize(n,true);
			long long minArea=9223372036854775807;
			for (int i=0;i<n-1;i++){
				for (int j=i+1;j<n;j++){
					flags[i]=false;
					flags[j]=false;
					//calc area
					int minX=1000000001;
					int minY=1000000001;
					int maxX=-1000000001;
					int maxY=-1000000001;
					for (int k=0;k<n;k++){
						if (flags[k]){
							minX=std::min(minX,x[k]);
							minY=std::min(minY,y[k]);

							maxX=std::max(maxX,x[k]);
							maxY=std::max(maxY,y[k]);
						}
					}
					minX--;
					minY--;
					maxX++;
					maxY++;
					long long minEdge=std::max(maxX-minX,maxY-minY);
					minArea=std::min(minArea,minEdge*minEdge);
					flags[i]=true;
					flags[j]=true;
				}
			}
			return minArea;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 1, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4LL; verify_case(0, Arg2, minArea(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {-1, -1, 0, 2, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {-2, -1, 0, -1, -2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 9LL; verify_case(1, Arg2, minArea(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1000000000, -1000000000, 1000000000, -1000000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1000000000, 1000000000, -1000000000, -1000000000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 4000000008000000004LL; verify_case(2, Arg2, minArea(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {93, 34, 12, -11, -7, -21, 51, -22, 59, 74, -19, 29, -56, -95, -96, 9, 44, -37, -54, -21}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {64, 12, -43, 20, 55, 74, -20, -54, 24, 20, -18, 77, 86, 22, 47, -24, -33, -57, 5, 7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); long long Arg2 = 22801LL; verify_case(3, Arg2, minArea(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        MinimumSquareEasy ___test;
        ___test.run_test(-1);
//		___test.run_test(2);
        system("pause");
        return 0;
}
// END CUT HERE

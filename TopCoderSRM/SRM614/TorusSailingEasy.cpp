// BEGIN CUT HERE

// END CUT HERE
#line 5 "TorusSailingEasy.cpp"
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
const double eps=1e-5;

int n,m;
const int MAX_DAYS = 11*11;
const int MAX_I = 1000;
class TorusSailingEasy
{
        public:
        double expectedTime(int N, int M, int goalX, int goalY)
        {
			int xPos=0;
			int yPos=0;
			int i=0;
			int x=-1;
			bool passFlag=false;
			for (;;i++){
				xPos=i%N;
				yPos=i%M;
				if (xPos==0 && yPos==0 ){
					if (!passFlag){
						passFlag=true;
					}
					else{
						break;
					}
				}
				else if (xPos==goalX && yPos==goalY){
					x=i;
				}
			}
			if (x==-1){
				return -1.0f;
			}
			int y=i-x;
			if (y>x){
				swap(x,y);
			}
			int c[MAX_I+1][MAX_DAYS];
			for (int i=0;i<=MAX_DAYS;i++){
				c[0][i]=0;
			}
			c[0][y]=1;
			for (int i=1;i<=MAX_I;i++){
				for (int j=0;j<=x+y;j++){
					c[i][j]=0;
					if (j<=x+y-2){
						c[i][j]+=c[i-1][j+1];
					}
					if (j>=2){
						c[i][j]+=c[i-1][j-1];
					}
				}
			}
			double possib=0.0f;
			for (int i=1;i<=MAX_I;i++){
				double curPossib=double(c[i][0]+c[i][x+y]);
				possib+=double(i)*curPossib/pow(2.0,double(i));
			}
			return possib;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; double Arg4 = 1.0; verify_case(0, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 0; int Arg3 = 1; double Arg4 = -1.0; verify_case(1, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; double Arg4 = 2.0; verify_case(2, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 1; int Arg3 = 3; double Arg4 = 27.0; verify_case(3, Arg4, expectedTime(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        TorusSailingEasy ___test;
        //___test.run_test(-1);
		___test.run_test(2);
        system("pause");
        return 0;
}
// END CUT HERE

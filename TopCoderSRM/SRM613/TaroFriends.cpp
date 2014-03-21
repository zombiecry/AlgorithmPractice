// BEGIN CUT HERE

// END CUT HERE
#line 5 "TaroFriends.cpp"
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
class TaroFriends
{
        public:
		bool CheckIn(int x,int a,int b){
			return (x<=b && x>=a);
		}
        int getNumber(vector <int> coordinates, int X)
        {
            typedef std::vector <int> CVec;
			CVec a(coordinates.size());
			CVec b(coordinates.size());
			CVec c(coordinates.size(),-1);
			int n=coordinates.size();
			int i=0;
			unsigned int minDist=0xffffffff;
			while(i>=0){
				c[i]++;
				if (c[i]>=2){	//backtrack
					c[i]=-1;
					i--;
				}
				else {
					int x1=coordinates[i]+X;
					int x2=coordinates[i]-X;
					if (c[i]==0 && i>0){	//do the cut
						if (CheckIn(x1,a[i-1],b[i-1])||
							CheckIn(x2,a[i-1],b[i-1])){
								c[i]=2;			//disable traceback
								a[i]=a[i-1];
								b[i]=b[i-1];
								if (i==n-1){
									int dist=b[i]-a[i];
									if (dist<minDist){
										minDist=dist;
									}
								}
								else{
									i++;
								}
								continue;
						}
					}
					int x=c[i]==0?x1:x2;
					if (i>0){
					a[i]=min(x,a[i-1]);
					b[i]=max(x,b[i-1]);
					}
					else{
						a[i]=b[i]=x;
					}
					if (i==n-1){
						int dist=b[i]-a[i];
						if (dist<minDist){
							minDist=dist;
						}
					}
					else{
						i++;
					}
				}
			}
			return minDist;
			
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-3, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 3; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {4, 7, -7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 4; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {-100000000, 100000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100000000; int Arg2 = 0; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3, 7, 4, 6, -10, 7, 10, 9, -5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; int Arg2 = 7; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {-4, 0, 4, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; verify_case(4, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; verify_case(5, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        TaroFriends ___test;
        ___test.run_test(-1);
        system("pause");
        return 0;
}
// END CUT HERE

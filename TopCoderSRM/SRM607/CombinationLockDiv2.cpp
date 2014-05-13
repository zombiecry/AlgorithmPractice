// BEGIN CUT HERE 

// END CUT HERE
#line 5 "CombinationLockDiv2.cpp"
#include <vector>
#include <list>
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


typedef std::pair <int,int> scPair2i;
typedef std::vector <int> scVeci;
typedef std::vector <scPair2i> scVec2i;
typedef std::stack  <int> scStacki;
typedef std::queue  <int> scQueuei;
typedef std::set    <int> scSeti;
typedef std::map<int,int> scMapii;
typedef std::map<int,int>::iterator scMapiiIter;
typedef std::map<int,int>::reverse_iterator scMapiiRevIter;
#define tr(container,it)    \
    for (it=container.begin();it!=container.end();it++)
#define trRev(container,it)    \
	for (it=container.rbegin();it!=container.rend();it++)
#define scFor0(x,num) \
	for (int x=0;x<num;x++)
#define scFor1(x,start,num) \
	for (int x=start;x<num;x++)
const int INF=0x7fffffff;

int m,n;
class CombinationLockDiv2
        { 
        public: 
			scVeci c;
			int    mem[52][9*50+2][3];
		int Solve(int p,int x,int dir){
			if (p==n){
				return 0;
			}
			if (mem[p][x][dir+1]!=-1){
				return mem[p][x][dir+1];
			}
			int res=0x7fffffff;
			scFor1(d,-1,2){
				if (d==0){
					continue;
				}
				scFor1(y,0,9*n+1){
					if ((c[p]+d*y)%10 != 0){
						continue;
					}
					if (d*dir>0){
						res=min(res,max(y-x,0)+Solve(p+1,y,d));
					}
					else{
						res=min(res,y+Solve(p+1,y,d));
					}
				}
			}
			mem[p][x][dir+1]=res;
			return res;
		}
        int minimumMoves(string S, string T) 
            { 
				n=S.length();
				c.resize(n);
				memset(mem,-1,sizeof(mem));
				scFor0(i,n){
					c[i]=(S[i]-T[i]+10)%10;
				}
				int res=Solve(0,0,-1);
				return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "123"; string Arg1 = "112"; int Arg2 = 1; verify_case(0, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "1"; string Arg1 = "7"; int Arg2 = 4; verify_case(1, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "607"; string Arg1 = "607"; int Arg2 = 0; verify_case(2, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "1234"; string Arg1 = "4567"; int Arg2 = 3; verify_case(3, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "020"; string Arg1 = "909"; int Arg2 = 2; verify_case(4, Arg2, minimumMoves(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "4423232218340"; string Arg1 = "6290421476245"; int Arg2 = 18; verify_case(5, Arg2, minimumMoves(Arg0, Arg1)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        CombinationLockDiv2 ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

// BEGIN CUT HERE 

// END CUT HERE
#line 5 "BlackBoxDiv2.cpp"
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

typedef long long int scLLi;
typedef long long unsigned int scLLui;
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
#define scForInv1(x,start,end) \
	for (int x=start;x>=end;x--)
const int MODNUM=1000000007;
int m,n;
class BlackBoxDiv2
        { 
        public: 
			int w,h;
			scLLi c[51][51];
			scLLi mem[51][51];
		scLLi Comb(int a,int b){
			b=max(b,a-b);
			if (c[a][b]!=-1){
				return c[a][b];
			}
			if (a==0){
				if (b==a){
					c[a][b]=1;
					return 1;
				}
				c[a][b]=0;
				return 0;
			}
			if (b==a){
				c[a][b]=1;
				return 1;
			}
			scLLi up=1;
			scLLi down=1;
			scForInv1(x,a,b+1){
				up*=x;
				while(down<=a-b && up%down==0){
					up/=down;
					down++;
				}
			}
			c[a][b]=up;
			return up;
		}
		scLLi Solve(int x,int y){
			if (mem[x][y]!=-1){
				return mem[x][y];
			}
			if (x==0 && y==0){
				mem[x][y]=1;
				return 1;
			}
			if (x==0){
				mem[x][y]=0;
				return 0;
			}
			scLLi res=0;
			scFor0(i,y+1){
				scFor0(j,h-y+1){
					if (i+j<1){
						continue;
					}
					scLLi cur=1;
					cur*=Comb(y,i);
					cur*=Comb(h-y,j);
					cur%=MODNUM;
					cur*=Solve(x-1,y-i);
					cur%=MODNUM;
					res+=cur;
					res%=MODNUM;
				}
			}
			mem[x][y]=res;
			return res;
		}

        int count(string front, string side) 
            { 
				w=front.length();
				h=side.length();
				scFor0(i,front.length()){
					if (front[i]=='.'){
						w--;
					}
				}
				scFor0(i,side.length()){
					if (side[i]=='.'){
						h--;
					}
				}
				memset(c,-1,sizeof(c));
				memset(mem,-1,sizeof(mem));
				int res=Solve(w,h);
				return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "BB"; string Arg1 = "BB"; int Arg2 = 7; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "..."; string Arg1 = "....."; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "..."; string Arg1 = "BBB"; int Arg2 = 0; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "...BB.B...."; string Arg1 = "B.B.B.B.B"; int Arg2 = 16081; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "BBBBB.BBBBBBBBB.BBBBBBB.BBBB.B.BB..BB.B.BBBBBBBBBB"; string Arg1 = ".B.BBB..BBBBBB.BBBB.B...BBBB.BB.BBBBBBBBBB.....BBB"; int Arg2 = 771030153; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        BlackBoxDiv2 ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

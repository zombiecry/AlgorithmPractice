// BEGIN CUT HERE 

// END CUT HERE
#line 5 "PalindromeMatrixDiv2.cpp"
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

int m,n;
#define GETX(num) \
	((num)%m)
#define GETY(num) \
	((num)/m)
#define GETNUM(y,x) \
	((y)*m+(x))
const int INF=0x7fffffff;
class PalindromeMatrixDiv2
        { 
        public: 
			int c[65][65];
			int vis[65];
        int minChange(vector <string> A, int rowCount, int columnCount) 
            { 
				n=A.size();
				m=A[0].size();
				scVeci rv(n,0);
				scVeci cv(m,0);
				int rc=rowCount;
				int cc=columnCount;
				scFor0(i,rc){
					rv[n-1-i]=1;
				}
				scFor0(i,cc){
					cv[m-1-i]=1;
				}
				int res=INF;
				do{
					do{
						memset(c,0,sizeof(c));
						memset(vis,-1,sizeof(vis));
						scFor0(i,n){
							if (rv[i]){
								scFor0(j,m/2){
									int u=GETNUM(i,j);
									int v=GETNUM(i,m-1-j);
									c[u][v]=1;
									c[v][u]=1;
									vis[u]=0;
									vis[v]=0;
								}
							}
						}
						scFor0(i,m){
							if (cv[i]){
								scFor0(j,n/2){
									int u=GETNUM(j	  ,i);
									int v=GETNUM(n-1-j,i);
									c[u][v]=1;
									c[v][u]=1;
									vis[u]=0;
									vis[v]=0;
								}
							}
						}
						int change=0;
						scFor0(i,m*n){
							if (vis[i]==0){
								//dfs a scc
								scStacki st;
								st.push(i);
								vis[i]=1;
								int a=0;
								int b=0;
								while(!st.empty()){
									int u=st.top();
									st.pop();
									if (A[GETY(u)][GETX(u)]=='1'){
										a++;
									}
									else{
										b++;
									}
									vis[u]=2;
									scFor0(v,m*n){
										if (c[u][v] && vis[v]==0){
											st.push(v);
											vis[v]=1;
										}
									}
								}
								change+=min(a,b);
							}
						}
						res=min(res,change);
					}while(next_permutation(cv.begin(),cv.end()));
				}while(next_permutation(rv.begin(),rv.end()));
				return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0000"
,"1000"
,"1100"
,"1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"0000"
,"1000"
,"1100"
,"1110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 2; int Arg3 = 3; verify_case(1, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"01"
,"10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; verify_case(2, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"1110"
,"0001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(3, Arg3, minChange(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 8; verify_case(4, Arg3, minChange(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        PalindromeMatrixDiv2 ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

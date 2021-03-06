// BEGIN CUT HERE 

// END CUT HERE
#line 5 "MiningGoldEasy.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
class MiningGoldEasy
        { 
        public: 
		int N;
		int M;
		scVeci event_i;
        scVeci event_j;
		int mem[50][50][50];
		int Solve(int x,int y,int eStart){
			if (mem[x][y][eStart]!=-1){
				return mem[x][y][eStart];
			}

			int curGold=0;
			curGold=M+N-(abs(event_i[x]-event_i[eStart])+abs(event_j[y]-event_j[eStart]));
			if (eStart==n-1){
				mem[x][y][eStart]=curGold;
				return curGold;
			}
			int resGold=-1;
			scFor1(i,eStart+1,n){
				resGold=max(Solve(x,i,eStart+1),resGold);
				resGold=max(Solve(i,y,eStart+1),resGold);
			}
			mem[x][y][eStart]=curGold+resGold;
			return mem[x][y][eStart];
		}
        int GetMaximumGold(int N, int M, vector <int> event_i, vector <int> event_j) 
            { 
				n=event_i.size();
				scFor0(i,n){
					scFor0(j,n){
						scFor0(k,n){
							mem[i][j][k]=-1;
						}
					}
				}
				this->N=N;
				this->M=M;
				this->event_i=event_i;
				this->event_j=event_j;
				int gold=-1;
				scFor0(i,n){
					scFor0(j,n){
						gold=max(gold,Solve(i,j,0));
					}
				}
				return gold;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 4; verify_case(0, Arg4, GetMaximumGold(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {0, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 7; verify_case(1, Arg4, GetMaximumGold(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {0, 3, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {0, 3, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 15; verify_case(2, Arg4, GetMaximumGold(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 3; int Arg1 = 4; int Arr2[] = {0, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {4, 1}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 11; verify_case(3, Arg4, GetMaximumGold(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 6; int Arr2[] = {0, 4, 2, 5, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {3, 4, 5, 6, 0}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 48; verify_case(4, Arg4, GetMaximumGold(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 557; int Arg1 = 919; int Arr2[] = {81, 509, 428, 6, 448, 149, 77, 142, 40, 405, 109, 247}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arr3[] = {653, 887, 770, 477, 53, 637, 201, 863, 576, 393, 512, 243}; vector <int> Arg3(Arr3, Arr3 + (sizeof(Arr3) / sizeof(Arr3[0]))); int Arg4 = 16255; verify_case(5, Arg4, GetMaximumGold(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        MiningGoldEasy ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

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
			scVeci diff;
			scVeci iS;
			scVeci iT;
			int Solve(int s,int l){
				int a1=diff[s];
				int rotType=0;
				int rot=INF;
				if (a1<=0){
					rotType=(a1>-5)?0:1;
				}
				else if (a1>0){
					rotType=(a1>5)?0:1;
				}
				scFor1(i,s,s+l){
					int dx=(diff[i]);
					if (rotType==0){
						if (dx<0){

						}
						else if (dx>0){

						}
						else{
							return 0;
						}
					}
					else if (rotType==1){

					}
				}
				scFor1(i,s,s+l){
					int dx=(diff[i]);
					if (rotType==0){
						if (dx<0){

						}
						else if (dx>0){

						}
						else{
							return 0;
						}
					}
					else if (rotType==1){

					}
				}

				scFor1(i,s,s+l){
					if (rotType==0){

					}
					else if (rotType==1){

					}
				}
				scFor1(i,s,s+l){
					diff[i]=iS[i]-iT[i];
				}
				return rot;
			}
        int minimumMoves(string S, string T) 
            { 
				n=S.length();
				diff.resize(n);
				iS.resize(n);
				iT.resize(n);
				scFor0(i,n){
					iS[i]=S[i]-'0';
					iT[i]=T[i]-'0';
					diff[i]=iS[i]-iT[i];
				}
				int mNum=0;
				for (int l=n;l>=1;l--){
					scFor0(i,n+1-l){
						mNum+=Solve(i,l);
					}
				}
				return mNum;
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
        ___test.run_test(3); 
        system("pause");
        } 
    // END CUT HERE 

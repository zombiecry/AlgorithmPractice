// BEGIN CUT HERE 

// END CUT HERE
#line 5 "AlienAndSetDiv2.cpp"
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
const  scLLi MODNUM=1000000007L;
int m,n;
class AlienAndSetDiv2
        { 
        public: 
			int K;
			typedef set<int,greater<int>> mySet;
			typedef map <mySet,scLLi> myMap;
			myMap cMap[101];
		scLLi Solve(int p,mySet s){
			if (cMap[p].count(s)){
				return cMap[p][s];
			}
			if (p==0){
				if (s.empty()){
					cMap[p][s]=1;
					return 1;
				}
				cMap[p][s]=0;
				return 0;
			}
			scLLi res=0;
			if (s.empty()){
				mySet ns=s;
				ns.insert(p);
				res=(2*Solve(p-1,ns)) % MODNUM;
			}
			else {
				int xn=*s.begin();
				mySet ns1=s;
				ns1.erase(xn);
				res+=Solve(p-1,ns1);		//why not mult 2?
				if (xn<p+K){
					mySet ns2=s;
					ns2.insert(p);
					res+=Solve(p-1,ns2);
					res %= MODNUM;
				}
			}
			cMap[p][s]=res;
			return cMap[p][s];
		}

        int getNumber(int N, int K) 
            { 
				n=N;
				this->K=K;
				mySet s;
				int res=Solve(2*n,s);
				return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 4; verify_case(0, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 8; verify_case(1, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 44; verify_case(2, Arg2, getNumber(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 10; int Arg2 = 184756; verify_case(3, Arg2, getNumber(Arg0, Arg1)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        AlienAndSetDiv2 ___test; 
        ___test.run_test(3); 
        system("pause");
        } 
    // END CUT HERE 

// BEGIN CUT HERE

// END CUT HERE
#line 5 "BoxesDiv2.cpp"
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


typedef std::pair <int,int> scPair2i;
#define scFor0(x,num) \
	for (int x=0;x<num;x++)
#define scFor1(x,start,num) \
	for (int x=start;x<num;x++)


int n,m;
class BoxesDiv2
{
        public:
			
        int findSize(vector <int> candyCounts)
        {
			n=candyCounts.size();
            set <scPair2i> s;
			scFor0(i,n){
				int cur=1;
				while(cur<candyCounts[i]){
					cur*=2;
				}
				s.insert(scPair2i(cur,i));
			}
			int count=n;
			while(s.size()>=2){
				set<scPair2i>::iterator it=s.begin();
				scPair2i a;
				scPair2i b;
				a=*it;
				s.erase(it);
				it=s.begin();
				b=*it;
				s.erase(it);
				scPair2i c;
				c.first=max(a.first,b.first)*2;
				c.second=a.second;
				s.insert(c);
			}
			int res=(*s.begin()).first;
			return res;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {8,8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(0, Arg1, findSize(Arg0)); }
	void test_case_1() { int Arr0[] = {5,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(1, Arg1, findSize(Arg0)); }
	void test_case_2() { int Arr0[] = {1,7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; verify_case(2, Arg1, findSize(Arg0)); }
	void test_case_3() { int Arr0[] = {1,1,13,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 32; verify_case(3, Arg1, findSize(Arg0)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1024; verify_case(4, Arg1, findSize(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        BoxesDiv2 ___test;
        ___test.run_test(-1);
        system("pause");
        return 0;
}
// END CUT HERE

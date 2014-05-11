// BEGIN CUT HERE

// END CUT HERE
#line 5 "PairGameEasy.cpp"
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
typedef long long int scLLi;
typedef long long unsigned int scLLUi;
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
#define scForInv1(x,start,end) \
	for (int x=start;x>=end;x--)


int n,m;
class PairGameEasy
{
        public:
        string able(int a, int b, int c, int d)
        {
            string pos="Able to generate";
			string impos="Not able to generate";
			scPair2i des(c,d);
			if (scPair2i(a,b)==des){
				return pos;
			}
			queue <scPair2i> que;
			que.push(scPair2i(a,b));
			while(!que.empty()){
				scPair2i top=que.front();
				que.pop();
				scPair2i np1(top.first+top.second,top.second);
				scPair2i np2(top.first           ,top.first+top.second);
				if (np1==des || np2==des){
					return pos;
				}
				else{
					if (np1.first<=des.first && np1.second<=des.second){
						que.push(np1);
					}
					if (np2.first<=des.first && np2.second<=des.second){
						que.push(np2);
					}
				}
			}
			return impos;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 3; int Arg3 = 5; string Arg4 = "Able to generate"; verify_case(0, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; string Arg4 = "Not able to generate"; verify_case(1, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 999; string Arg4 = "Not able to generate"; verify_case(2, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1000; string Arg4 = "Able to generate"; verify_case(3, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 58; int Arg2 = 384; int Arg3 = 221; string Arg4 = "Able to generate"; verify_case(4, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 1000; int Arg2 = 1000; int Arg3 = 1000; string Arg4 = "Able to generate"; verify_case(5, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        PairGameEasy ___test;
        ___test.run_test(-1);
        system("pause");
        return 0;
}
// END CUT HERE

// BEGIN CUT HERE

// END CUT HERE
#line 5 "TwoWaysSorting.cpp"
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


int n,m;
class TwoWaysSorting
{
        public:
        string sortingMethod(vector <string> stringList)
        {
			n=stringList.size();
            vector <string> lstr=stringList;
			sort(lstr.begin(),lstr.end());
			bool s1=true;
			scFor0(i,stringList.size()){
				if (stringList[i]!=lstr[i]){
					s1=false;
					break;
				}
			}
			scVeci sVec(n);
			scFor0(i,n){
				sVec[i]=stringList[i].length();
			}
			sort(sVec.begin(),sVec.end());
			bool s2=true;
			scFor0(i,n){
				if (stringList[i].length()!=sVec[i]){
					s2=false;
					break;
				}
			}
			if (s1 && s2){
				return "both";
			}
			if (s1){
				return "lexicographically"; 
			}
			if (s2){
				return "lengths";
			}
			return "none";
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"a", "aa", "bbb"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "both"; verify_case(0, Arg1, sortingMethod(Arg0)); }
	void test_case_1() { string Arr0[] = {"c", "bb", "aaa"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lengths"; verify_case(1, Arg1, sortingMethod(Arg0)); }
	void test_case_2() { string Arr0[] = {"etdfgfh", "aio"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "none"; verify_case(2, Arg1, sortingMethod(Arg0)); }
	void test_case_3() { string Arr0[] = {"aaa", "z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lexicographically"; verify_case(3, Arg1, sortingMethod(Arg0)); }
	void test_case_4() { string Arr0[] = {"z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "both"; verify_case(4, Arg1, sortingMethod(Arg0)); }
	void test_case_5() { string Arr0[] = {"abcdef", "bcdef", "cdef", "def", "ef", "f", "topcoder"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "lexicographically"; verify_case(5, Arg1, sortingMethod(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        TwoWaysSorting ___test;
        ___test.run_test(-1);
        system("pause");
        return 0;
}
// END CUT HERE

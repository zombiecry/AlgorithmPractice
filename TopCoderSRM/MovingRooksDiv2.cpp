// BEGIN CUT HERE 

// END CUT HERE
#line 5 "MovingRooksDiv2.cpp"
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
#define tr(container,it)    \
    for (it=container.begin();it!=container.end();it++)
typedef std::pair <int,int> scPair2i;
int n;
class MovingRooksDiv2
        { 
        public: 
        string move(vector <int> Y1, vector <int> Y2) 
            { 
				n=Y1.size();
				map <int,int> cMap;
				for (int i=0;i<n;i++){
					cMap[Y1[i]]=i;
				}
				bool canFlag=true;
				for (int i=0;i<n;i++){
					if (Y1[i]!=Y2[i]){
						int r1=i;
						int c1=Y1[i];
						int c2=Y2[i];
						if (c1<c2){
							canFlag=false;
							break;
						}
						if (!cMap.count(c2)){
							canFlag=false;
							break;
						}
						int r2=cMap[Y2[i]];
						if (r2<r1){
							canFlag=false;
							break;
						}
						cMap.erase(cMap[c2]);
						cMap[c1]=r2;
						Y1[r2]=c1;
					}
				}
				if (canFlag){
					return "Possible";
				}
				else {
					return "Impossible";
				}
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, move(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, move(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, move(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3,1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(3, Arg2, move(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3,1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(4, Arg2, move(Arg0, Arg1)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        MovingRooksDiv2 ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

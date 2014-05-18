// BEGIN CUT HERE 

// END CUT HERE
#line 5 "GraphWalkWithProbabilities.cpp"
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

int m,n;
class GraphWalkWithProbabilities
        { 
        public: 
			double c[2][51];
        double findprob(vector <string> graph, vector <int> winprob, vector <int> looseprob, int Start) 
            { 
            //$CARETPOSITION$ 
				n=winprob.size();
				scFor0(i,n){
					c[0][i]=c[1][i]=0.0;
				}
				scVeci conProb;
				conProb.resize(n);
				scFor0(i,n){
					conProb[i]=100-winprob[i]-looseprob[i];
				}
				scFor0(t,10000){
					scFor0(i,n){
						c[1][i]=0.0;
						scFor0(j,n){
							if (graph[i][j]=='1'){
								double q=winprob[j]/100.0 + conProb[j]*c[0][j]/100.0;
								c[1][i]=max(c[1][i],q);
							}
						}
					}
					memcpy(c[0],c[1],sizeof(c[1]));
				}
				return c[0][Start];
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; double Arg4 = 0.5; verify_case(0, Arg4, findprob(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"11","11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {60,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {40,60}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; double Arg4 = 0.6; verify_case(1, Arg4, findprob(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"11","11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; double Arg4 = 0.4285714285714286; verify_case(2, Arg4, findprob(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"110","011","001"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,1,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20,20,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; double Arg4 = 0.405; verify_case(3, Arg4, findprob(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"111","111","011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {100,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,50,50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; double Arg4 = 0.5; verify_case(4, Arg4, findprob(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        GraphWalkWithProbabilities ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

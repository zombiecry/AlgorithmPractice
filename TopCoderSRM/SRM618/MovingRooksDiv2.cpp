// BEGIN CUT HERE 

// END CUT HERE
#line 5 "MovingRooksDiv2.cpp"
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


int n;
struct State{
	vector <int> y;
};
class MovingRooksDiv2
        { 
        public: 
		bool Equal(scVeci &v1,scVeci &v2){
			scFor1(i,0,n){
				if (v1[i]!=v2[i]){
					return false;
				}
			}
			return true;
		}


        string move(vector <int> Y1, vector <int> Y2) 
            { 
				n=Y1.size();
				//bfs
				State s0;
				s0.y=Y1;
				queue <State> que;
				que.push(s0);
				string posStr="Possible";
				string imposStr="Impossible";
				set <scVeci> visitedStates;
				visitedStates.insert(Y1);
				while (!que.empty()){
					State &sTop=que.front();
					if (Equal(sTop.y,Y2)){
						return posStr;
					}
					scFor1(i,0,n-1){
						scFor1(j,i+1,n){
							if (sTop.y[i]>sTop.y[j]){
								State genStat;
								genStat.y=sTop.y;
								swap(genStat.y[i],genStat.y[j]);
								if (visitedStates.find(genStat.y)==visitedStates.end()){
									que.push(genStat);
									visitedStates.insert(genStat.y);
								}
							}
						}
					}
					que.pop();
				}
				return imposStr;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();
	if ((Case == -1) || (Case == 5)) test_case_5();
	}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(0, Arg2, move(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(1, Arg2, move(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(2, Arg2, move(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3,1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,2,1,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Possible"; verify_case(3, Arg2, move(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {3,1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3,2,0,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Impossible"; verify_case(4, Arg2, move(Arg0, Arg1)); }
	void test_case_5() {
		int Arr0[] = {7, 0, 4, 6, 5, 3, 1, 2};
		vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
		int Arr1[] = {4, 1, 5, 7, 2, 3, 6, 0}; 
		vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); 
		string Arg2 = "Impossible"; 
		verify_case(5, Arg2, move(Arg0, Arg1)); 
	}
// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        MovingRooksDiv2 ___test; 
        ___test.run_test(5); 
        system("pause");
        } 
    // END CUT HERE 

// BEGIN CUT HERE

// END CUT HERE
#line 5 "RandomGraph.cpp"
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
class RandomGraph
{
        public:
			double c[51];
			double P1[51];
			double P2[51];
			double P3[51];
			double Q[51*3];
        double probability(int n, int p)
        {
			c[1]=c[2]=c[3]=1;
			if (n<=3){
				return 1.0-c[n];
			}
			double p0=p/1000.0;
			double q=1.0-p0;
			scFor1(i,4,n+1){
				P1[i]=pow(q,i-1);
				P2[i]=(i-1)*p0*pow(q,2*(i-2));
				P3[i]=(i-1)*(i-2)*pow(p0,2)*pow(q,3*(i-3))*(0.5+q);
			}
			Q[0]=1;
			scFor1(i,1,n*3){
				Q[i]=Q[i-1]*(1-p0);
			}
			scFor1(i,4,n+1){
				//c[i]=P1[i]*c[i-1]+P2[i]*c[i-2]+P3[i]*c[i-3];
				c[i]=Q[i-1]*c[i-1]+
					 (i-1)*p0*Q[2*(i-2)]*c[i-2]+
					 (i-1)*(i-2)*p0*p0*Q[3*(i-3)]*(1.5-p0)*c[i-3];
			}
			return 1.0-c[n];

        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 7; int Arg1 = 0; double Arg2 = 0.0; verify_case(0, Arg2, probability(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 620; double Arg2 = 0.0; verify_case(1, Arg2, probability(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 500; double Arg2 = 0.59375; verify_case(2, Arg2, probability(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 8; int Arg1 = 100; double Arg2 = 0.33566851611343496; verify_case(3, Arg2, probability(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 15; int Arg1 = 50; double Arg2 = 0.5686761670525845; verify_case(4, Arg2, probability(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 10; double Arg2 = 0.7494276522159893; verify_case(5, Arg2, probability(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 50; int Arg1 = 1000; double Arg2 = 1.0; verify_case(6, Arg2, probability(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        RandomGraph ___test;
        ___test.run_test(4);
        system("pause");
        return 0;
}
// END CUT HERE

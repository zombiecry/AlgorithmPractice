// BEGIN CUT HERE 

// END CUT HERE
#line 5 "PeriodicJumping.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include<queue>
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


int m,n;
class PeriodicJumping
        { 
        public: 
			vector<int> l;
        int minimalTime(int x, vector <int> jumpLengths) 
            { 
				l=jumpLengths;
				n=l.size();
				x=abs(x);
				long long sum=0;
				long long maxv=0;
				int count=0;
				long long acc=0;
				for(int i=0;i<n;i++){
					if (acc>x) break;
					else acc+=l[i];
				}
				if (acc<x){
					int cc=x/acc;
					sum=cc*acc;
					count=cc*n;
				}
				while(sum<x || maxv-(sum-maxv)>x){
					long long cur=l[(count++)%n];
					sum+=cur;
					maxv=max(maxv,cur);
				}
				return count;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	//void test_case_0() { int Arg0 = 15; int Arr1[] = {1,2,3,4,5,6,7,8,9,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arr1[] = {10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; verify_case(2, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = -10; int Arr1[] = {2,3,4,500,6,7,8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; verify_case(3, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = -1000000000; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000000000; verify_case(4, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 0; int Arr1[] = {19911120}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(5, Arg2, minimalTime(Arg0, Arg1)); }
	void test_case_0() {
		int Arg0 = -1000000000;
		int Arr1[] = {954311621, 771996165, 394202445, 337189612, 20882330, 922733588, 929067594, 630034197, 589159523, 969241521, 328315898, 942657237, 105352851, 462623375, 531567235, 970412687, 761398068, 990064744, 759639986, 901139976, 36424252, 68066626, 820050340, 137556633, 40263955, 615536887, 481780250, 738217063, 752224586, 299019398, 261961546, 80828671, 774973392, 627144560, 224390165, 13289419, 255580308, 35060755, 101124284, 612899229, 82920852, 879038374, 1646227, 546060693, 593608780, 900413112, 633378968, 349556345, 772447089, 775105441};
		vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = 2;
		verify_case(0, Arg2, minimalTime(Arg0, Arg1)); 
	}

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        PeriodicJumping ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

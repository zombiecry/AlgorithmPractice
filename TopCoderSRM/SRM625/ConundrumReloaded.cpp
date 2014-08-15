// BEGIN CUT HERE 

// END CUT HERE
#line 5 "ConundrumReloaded.cpp"
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
class ConundrumReloaded
        { 
        public: 
			vector <int> a;
			vector <int> s;
		int Solve(int start,int infer){
			int xi=infer;
			int si=s[start];
			int p=start;
			int count=0;
			while (si!=-1){
				count+=xi;
				p=(p+1)%n;
				xi = xi ^ si;
				si = s[p];
				if (p==start){
					break;
				}
			}
			if (p == start) {
				if (xi != infer){
					return 9999;
				}
				return count;
			}
			//s[pos1]==-1
			count+=xi;
			return count;
		}
        int minimumLiars(string answers) 
            { 
                n=answers.size();
				s.resize(n);
				for (int i=0;i<n;i++){
					if (answers[i]=='L'){
						s[i]=1;
					}
					else if (answers[i]=='H'){
						s[i]=0;
					}
					else {
						s[i]=-1;
						a.push_back((i+1)%n);
					}
				}
				m=a.size();
				if (m==0){
					int n1=Solve(0,0);
					int n2=Solve(0,1);
					int res=min(n1,n2);
					if (res>999){
						return -1;
					}
					return res;
				}
				else{
					int res=0;
					for (int i=0;i<m;i++){
						int n1=Solve(a[i],0);
						int n2=Solve(a[i],1);
						res+=min(n1,n2);
					}
					return res;
				}
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LLH"; int Arg1 = 1; verify_case(0, Arg1, minimumLiars(Arg0)); }
	void test_case_1() { string Arg0 = "?????"; int Arg1 = 0; verify_case(1, Arg1, minimumLiars(Arg0)); }
	void test_case_2() { string Arg0 = "LHLH?"; int Arg1 = 2; verify_case(2, Arg1, minimumLiars(Arg0)); }
	void test_case_3() { string Arg0 = "??LLLLLL??"; int Arg1 = 3; verify_case(3, Arg1, minimumLiars(Arg0)); }
	void test_case_4() { string Arg0 = "LLL"; int Arg1 = -1; verify_case(4, Arg1, minimumLiars(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        ConundrumReloaded ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysScrabble.cpp"
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
typedef long long ll;
#define clr(x,a) memset(x,a,sizeof(x))
#define sz(x) (int)x.size()
#define see(x) cerr<<#x<<" "<<x<<endl
#define se(x) cerr<<" "<<x 
#define pb push_back
#define mp make_pair


int n,m;
class EllysScrabble
{
        public:
        string getMin(string letters, int maxDistance)
        {
            n=letters.length();
			vector <bool> cMap(n,false);
			string res=letters;
			int d=maxDistance;
			for (int i=0;i<n;i++){
				int pos=-1;
				char minCh='Z'+1;
				bool needFind=true;
				if (i-d >=0){
					if (!cMap[i-d]){
						pos=i-d;
						minCh=letters[i-d];
						needFind=false;
					}

				}
				if (needFind){
					for (int j=-d;j<=d;j++){
						int curPos=i+j;
						if (curPos>=0 && curPos<n){
							if (!cMap[curPos]){
								if (letters[curPos]<minCh){
									minCh=letters[curPos];
									pos=curPos;
								}
							}
						}
					}
				}

				
				res[i]=letters[pos];
				cMap[pos]=true;
			}
			return res;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "TOPCODER"; int Arg1 = 3; string Arg2 = "CODTEPOR"; verify_case(0, Arg2, getMin(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "ESPRIT"; int Arg1 = 3; string Arg2 = "EIPRST"; verify_case(1, Arg2, getMin(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "BAZINGA"; int Arg1 = 8; string Arg2 = "AABGINZ"; verify_case(2, Arg2, getMin(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; int Arg1 = 9; string Arg2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; verify_case(3, Arg2, getMin(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "GOODLUCKANDHAVEFUN"; int Arg1 = 7; string Arg2 = "CADDGAHEOOFLUKNNUV"; verify_case(4, Arg2, getMin(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"; int Arg1 = 6; string Arg2 = "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW"; verify_case(5, Arg2, getMin(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "ABRACADABRA"; int Arg1 = 2; string Arg2 = "AABARACBDAR"; verify_case(6, Arg2, getMin(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        EllysScrabble ___test;
        ___test.run_test(-1);
        system("pause");
        return 0;
}
// END CUT HERE
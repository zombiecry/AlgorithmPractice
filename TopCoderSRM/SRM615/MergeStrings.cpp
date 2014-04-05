// BEGIN CUT HERE 

// END CUT HERE
#line 5 "MergeStrings.cpp"
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

string gS,gA,gB;
int lenS,lenA,lenB;
class MergeStrings
        { 
        public: 
			bool MyLess(string A,string B){
				int minLen=std::min(A.length(),B.length());
				for (int i=0;i<minLen;i++){
					if (A[i]<B[i]){
						return true;
					}
					else if (A[i]>B[i]){
						return false;
					}
				}
				if (A.length()>=B.length()){
					return true;
				}
				return false;
			}
			bool f(int pS,int pA,int pB,string &res){
				if (pS==lenS){
					res="";
					return true;
				}
				string leftA=gA.substr(pA,string::npos);
				string leftB=gB.substr(pB,string::npos);
				char curS=gS[pS];
				char curA='*';
				if (pA<lenA){
					curA=gA[pA];
				}
				
				char curB='*';
				if (pB<lenB){
					curB=gB[pB];
				}
				string temp;
				if (MyLess(leftA,leftB)){	//a first
					if (curS=='?'){
						if (pA<lenA){
							temp+=curA;
							string tempRes;
							if (f(pS+1,pA+1,pB,tempRes)){
								temp+=tempRes;
								res=temp;
								return true;
							}
						}
						temp="";
						if (pB<lenB){
							temp+=curB;
							string tempRes;
							if (f(pS+1,pA,pB+1,tempRes)){
								temp+=tempRes;
								res=temp;
								return true;
							}
						}
					}
					else {
						if (curS==curA){
							temp+=curA;
							string tempRes;
							if (f(pS+1,pA+1,pB,tempRes)){
								temp+=tempRes;
								res=temp;
								return true;
							}
						}
						temp="";
						if (curS==curB){
							temp+=curB;
							string tempRes;
							if (f(pS+1,pA,pB+1,tempRes)){
								temp+=tempRes;
								res=temp;
								return true;
							}
						}
					}
				}
				else{
					if (curS=='?'){
						if (pB<lenB){
							temp+=curB;
							string tempRes;
							if (f(pS+1,pA,pB+1,tempRes)){
								temp+=tempRes;
								res=temp;
								return true;
							}
						}
						temp="";
						if (pA<lenA){
							temp+=curA;
							string tempRes;
							if (f(pS+1,pA+1,pB,tempRes)){
								temp+=tempRes;
								res=temp;
								return true;
							}
						}

					}
					else {
						if (curS==curB){
							temp+=curB;
							string tempRes;
							if (f(pS+1,pA,pB+1,tempRes)){
								temp+=tempRes;
								res=temp;
								return true;
							}
						}
						temp="";
						if (curS==curA){
							temp+=curA;
							string tempRes;
							if (f(pS+1,pA+1,pB,tempRes)){
								temp+=tempRes;
								res=temp;
								return true;
							}
						}
					}
				}
				return false;
			}
        string getmin(string S, string A, string B) 
            { 
				lenS=S.length();
				lenA=A.length();
				lenB=B.length();
				gS=S;
				gA=A;
				gB=B;
				string res;
				f(0,0,0,res);
				return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4();if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "??CC??"; string Arg1 = "ABC"; string Arg2 = "BCC"; string Arg3 = "ABCCBC"; verify_case(0, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "WHAT?"; string Arg1 = "THE"; string Arg2 = "WA"; string Arg3 = ""; verify_case(1, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "PARROT"; string Arg1 = "PARROT"; string Arg2 = ""; string Arg3 = "PARROT"; verify_case(2, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "???????????"; string Arg1 = "AZZAA"; string Arg2 = "AZAZZA"; string Arg3 = "AAZAZZAAZZA"; verify_case(3, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "????K??????????????D???K???K????????K?????K???????"; string Arg1 = "KKKKKDKKKDKKDDKDDDKDKK"; string Arg2 = "KDKDDKKKDDKDDKKKDKDKKDDDDDDD"; string Arg3 = "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK"; verify_case(4, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 ="WYTDYPFYWTBTCBWQIDFZLLWFW";string Arg1 = "WYTDYPFYWTBTCBWQIDFZLL";string Arg2 = "WFW";string Arg3="WYTDYPFYWTBTCBWQIDFZLLWFW"; verify_case(5, Arg3, getmin(Arg0, Arg1, Arg2));}
// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        MergeStrings ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

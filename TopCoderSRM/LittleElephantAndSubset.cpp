// BEGIN CUT HERE 

// END CUT HERE
#line 5 "LittleElephantAndSubset.cpp"
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

#define SCREL 0
int m,n;
class LittleElephantAndSubset
        { 
        public: 
			vector <int> a;
			int    pre[1<<11];
			int Summary(vector <int> &c,int end){
				int res=0;
				for (int i=0;i<=end;i++){
					res+=c[i];
				}
				return res;
			}
			int Calc(vector <int> &c){
				int res=1;
				int start=0;
				for (int i=0;i<c.size();i++){
					int num=0;
					for (int j=0;j<c[i];j++){
						num |= 1<<j;
					}
					num=num << start;
#if SCREL
#define GETPRE(x)	\
	pre[(x)]
#else
#define GETPRE(x)	\
	(((x) & 1) ==1) ? 1 : CalcPre((x)>>1)
#endif
					res*=GETPRE(num);
					if (res==0){break;}
					start+=c[i];
				}
				return res;
			}
			int CalcPre(int A){
				vector <int> s;
				for (int i=0;i<10;i++){
					if ((A >> i) & 1){
						s.push_back(i);
					}
				}
				int res=0;
				do{
					if (s[0]==0){continue;}
					long long dig=1;
					long long num=0;
					for (int i=s.size()-1;i>=0;i--){
						num+=s[i]*dig;
						dig*=10;
						if (num > n){
							break;
						}
					}
					if (num <= n){
						res++;
					}
					else{
						break;
					}
				}while(next_permutation(s.begin(),s.end()));
				return res;
			}
        int getNumber(int N) 
            { 
				n=N;
				//pre calc 
#if SCREL
				for (int i=1;i < 1<<11 ;i++){
					if ((i & 1) ==1 ){
						pre[i]=1;
						continue;
					}
					pre[i]=CalcPre(i>>1);
				}
#endif
				a.resize(11);
				for (int i=0;i<11;i++){
					a[i]=i-1;
				}
				a[0]=10;
				int res=0;
				for (int i=2;i<=11;i++){
					int j=0;	
					static int lastRes=0;
					vector <int> c(i,0);	//backtrack
					while (j>=0){
						c[j]++;
						int sum=Summary(c,j);
						if (sum < 11){
							if (j < i-2){
								j++;
							}
							else{			//j=i-2
								c[j+1]=11-sum;
								int temp=Calc(c);
								//res+=Calc(c);
								res+=temp;
								for (int i=0;i<c.size();i++){
									cout<<c[i]<<" , ";
								}
								cout<<endl;
								cout<<temp<<endl;
							}
						}
						else{
							c[j]=0;
							j--;
						}
					}
				}
				return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 7; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 767; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { int Arg0 = 47; int Arg1 = 25775; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { int Arg0 = 4777447; int Arg1 = 66437071; verify_case(3, Arg1, getNumber(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        LittleElephantAndSubset ___test; 
        ___test.run_test(0); 
        system("pause");
        } 
    // END CUT HERE 

// BEGIN CUT HERE 

// END CUT HERE
#line 5 "VocaloidsAndSongs.cpp"
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

#define MODNUM 1000000007
int m,n;
class VocaloidsAndSongs
        { 
        public: 
		scLLi mem[51][51];
		scLLi CalcC(int x,int y){
			x=max(x,y-x);
			if (mem[x][y]!=-1){
				return mem[x][y];
			}
			if (x==y || y==0){
				mem[x][y]=1;
				return mem[x][y];
			}
			if (x>y){
				cout<<"Error!\n\n\n\n\n\nError\n";
				return 0;
			}
			scLLUi up=1;
			int j=1;
			scForInv1(a,y,x+1){
				up*=a;
				while (j<=y-x && up%j==0){
					up/=j;
					j++;
				}
			}
			scLLUi res=up;
			mem[x][y]=((scLLUi)res)%MODNUM;
			return mem[x][y];
		}
		
        int count(int S, int gumi, int ia, int mayu) 
            { 
				int a[3];
				int b[3];
				int c;
				int s[3];
				s[0]=gumi;
				s[1]=ia;
				s[2]=mayu;
				n=S;
				memset(mem,-1,sizeof(mem));
				int sumS=0;
				scFor0(i,3){
					sumS+=s[i];
				}
				vector <scVeci> sVec;
				scLLUi res=0;
				scFor0(x,S+1){
					scFor0(y,S+1){
						scFor0(z,S+1){
							if (x<=s[0] &&y<=s[1] && z<=s[2]){
								a[0]=x;
								a[1]=y;
								a[2]=z;
								int sumA=x+y+z;
								c=sumS-2*n+sumA;
								if (c<0){
									continue;
								}
								int t1=s[1]-y-(s[0]-x);
								int t2=s[2]-z-c;
								b[1]=t1+t2;
								if (b[1]<0 || b[1]%2 !=0){
									continue;
								}
								b[1]/=2;
								b[2]=t2-b[1];
								if (b[2]<0){
									continue;
								}
								b[0]=s[0]-x-c-b[2];
								if (b[0]<0){
									continue;
								}
								int p[7];
								memcpy(p  ,a,3*sizeof(int));
								memcpy(p+3,b,3*sizeof(int));
								p[6]=c;
								int left=n;
								scLLUi combo=1;
								sVec.resize(sVec.size()+1);
								scFor0(ii,7){
									scLLUi cur=CalcC(p[ii],left);
									combo*=cur;
									combo=combo % MODNUM;
									left-=p[ii];
								}
								
								res+=(combo);
								res%=MODNUM;

							}	
						}
					}
				}
				return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 1; int Arg4 = 6; verify_case(0, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; int Arg4 = 9; verify_case(1, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 50; int Arg1 = 10; int Arg2 = 10; int Arg3 = 10; int Arg4 = 0; verify_case(2, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 18; int Arg1 = 12; int Arg2 = 8; int Arg3 = 9; int Arg4 = 81451692; verify_case(3, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 25; int Arg2 = 25; int Arg3 = 25; int Arg4 = 198591037; verify_case(4, Arg4, count(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        VocaloidsAndSongs ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

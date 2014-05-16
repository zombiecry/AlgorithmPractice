// BEGIN CUT HERE 

// END CUT HERE
#line 5 "FoxConnection2.cpp"
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

typedef long long int scLLi;
typedef long long unsigned int scLLui;
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
const  scLLi MODNUM=1000000007L;
int m,n;
class FoxConnection2
        { 
        public: 
			struct Node{
				scVeci chs;
			};
			vector <Node> nodes;
			scVeci A;
			scVeci B;
			int k;
			void BuildTree(){
				scVeci flags(n,0);
				scQueuei que;
				que.push(0);
				while(!que.empty()){
					int top=que.front();
					que.pop();
					flags[top]=1;
					scFor0(i,A.size()){
						int u=A[i]-1;
						int v=B[i]-1;
						if (u!=top && v!=top){
							continue;
						}
						if (v==top){
							swap(u,v);
						}
						if (flags[v]){
							continue;
						}
						nodes[top].chs.push_back(v);
						que.push(v);
					}
				}
			}
			int mem[51][51][51];
			scLLi Solve(int p,int s,int left){
				if (nodes[p].chs.size()==0){
					if (left==0){
						return 1;
					}
					return 0;
				}
				if (s>nodes[p].chs.size()){
					if (left==0){
						return 1;
					}
					return 0;
				}
				if (left==0){
					return 1;
				}
				if (mem[p][s][left]!=-1){
					return mem[p][s][left];
				}
				scLLi res=0;
				if (s==0){
					scFor0(i,nodes[p].chs.size()){
						res+=Solve(nodes[p].chs[i],0,left);
						res%=MODNUM;
						res+=Solve(nodes[p].chs[i],1,left-1);
						res%=MODNUM;
					}
				}
				else{
					res+=Solve(p,s+1,left)%MODNUM;
					res%=MODNUM;
					scFor1(x,1,left+1){
						res+=(Solve(nodes[p].chs[s-1],1,x-1)*Solve(p,s+1,left-x))%MODNUM;
						res%=MODNUM;
					}
				}
				mem[p][s][left]=res;
				return mem[p][s][left];
			}
        int ways(vector <int> A, vector <int> B, int k) 
            { 
				
				n=A.size();
				scFor0(i,A.size()){
					n=max(A[i],n);
					n=max(B[i],n);
				}
				nodes.resize(n);
				memset(mem,-1,sizeof(mem));
				this->A=A;
				this->B=B;
				this->k=k;
				BuildTree();
				int res=0;
				res+=(Solve(0,0,k))%MODNUM;
				res+=(Solve(0,1,k-1))%MODNUM;
				return res;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 3; verify_case(0, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(1, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 3; verify_case(2, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1,2,2,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 6; verify_case(3, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1,2,2,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; int Arg3 = 4; verify_case(4, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 20; int Arg3 = 923263934; verify_case(5, Arg3, ways(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(6, Arg3, ways(Arg0, Arg1, Arg2)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        FoxConnection2 ___test; 
        ___test.run_test(6); 
        system("pause");
        } 
    // END CUT HERE 

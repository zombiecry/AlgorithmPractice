// BEGIN CUT HERE

// END CUT HERE
#line 5 "TaroCards.cpp"
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
#define tr(container,it)		\
	for (it=container.begin();it!=container.end();it++)
typedef std::pair <int,int> scPair2i;


int n,m;
const int MAX_S= 1024-1;
const int MAX_R= 40;
const int MAX_N= 50;
#define HASNUM(x)	\
	(s & (1<<(x-1)))
ll c[MAX_N][MAX_S+1][MAX_R+1];

class TaroCards
{
        public:
		int Minus(int s,int x){
			if (x>10){
				return s;
			}
			return s-(s&(1<<(x-1)));	
		}
        long long getNumber(vector <int> first, vector <int> second, int K)
        {
			n=first.size();
			m=max(n-10,0);
			for (int s=0;s<=MAX_S;s++){
				for (int r=0;r<=m;r++){
					int a=first[0];
					int b=second[0];
					int mask=0;
					int rnum=0;
					if (a<=10){
						int temp=1<<(a-1);
						mask|=temp;
					}
					else{
						rnum++;
					}
					if (b<=10){
						int temp=1<<(b-1);
						mask|=temp;
					}
					else{
						rnum++;
					}
					if (mask!=s || rnum!=r){
						c[0][s][r]=0;
					}
					else{
						c[0][s][r]=1;
					}
				}
			}

			c[0][0][0]=1;

			set<int> cs;
			for (int i=1;i<n;i++){
				for (int s=0;s<=MAX_S;s++){
					for (int r=0;r<=m;r++){
						int a=first[i];
						int b=second[i];
						int mask[2]={0,0};
						int rnum[2]={0,0};
						if (a<=10){
							mask[0]=1<<(a-1);
						}
						else{
							rnum[0]=1;
						}
						if (b<=10){
							mask[1]=1<<(b-1);
						}
						else{
							rnum[1]=1;
						}
						int maskt=mask[0]|mask[1];
						int rnumt=rnum[0]+rnum[1];
						c[i][s][r]=c[i-1][s][r];
						if (((maskt & s)==maskt)&&
							(rnumt<=r)){	//can add ai,bi
							cs.clear();
							int s1,s2,s3;
							s1=Minus(s,a);
							s2=Minus(s,b);
							s3=Minus(s1,b);
							cs.insert(s);
							cs.insert(s1);
							cs.insert(s2);
							cs.insert(s3);
							set<int>::iterator it;

							tr(cs,it){
								c[i][s][r]+=c[i-1][*it][r-rnumt];
							}
						}
					}
				}
			}
			long long wayNum=0;
			for (int s=0;s<=MAX_S;s++){
				for (int r=0;r<=m;r++){
					int mask=1;
					int intNum=0;
					for (int i=0;i<10;i++){
						if (mask & s){
							intNum++;
						}
						mask=mask<<1;
					}
					intNum+=r;
					ll tmp=c[n-1][s][r];
					if (intNum<=K && tmp){
						wayNum+=tmp;
					}
				}
			}
			return wayNum;
			
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; long long Arg3 = 3LL; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {3, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; long long Arg3 = 8LL; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {4, 2, 1, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; long long Arg3 = 16LL; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2, 1, 10, 9, 3, 2, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; long long Arg3 = 17LL; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; long long Arg3 = 1LL; verify_case(4, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {6, 20, 1, 11, 19, 14, 2, 8, 15, 21, 9, 10, 4, 16, 12, 17, 13, 22, 7, 18, 3, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4, 5, 10, 7, 6, 2, 1, 10, 10, 7, 9, 4, 5, 9, 5, 10, 10, 3, 6, 6, 4, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 14; long long Arg3 = 2239000LL; verify_case(5, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_6() { 
	    int Arr0[]={42, 32, 6, 46, 17, 35, 9, 36, 11, 10, 41, 27, 31, 44, 19, 3, 2, 47, 26, 38, 1, 24, 20, 8, 16, 33, 28, 49, 48, 50, 37, 39, 40, 5, 23, 25, 34, 21, 18, 12, 22, 15, 14, 7, 30, 43, 4, 13, 29, 45};
		vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); 
		int Arr1[]={10, 8, 7, 10, 4, 6, 8, 7, 7, 6, 9, 3, 6, 5, 5, 2, 7, 2, 7, 4, 4, 6, 6, 4, 3, 9, 3, 6, 4, 7, 2, 9, 7, 3, 2, 5, 7, 3, 10, 2, 6, 1, 4, 7, 5, 10, 3, 10, 4, 5};
		vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0])));
		int Arg2 = 58;
		long long Arg3 = 1125899906842624LL;
		verify_case(6, Arg3, getNumber(Arg0, Arg1, Arg2)); 
	}

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        TaroCards ___test;
        ___test.run_test(6);
        system("pause");
        return 0;
}
// END CUT HERE

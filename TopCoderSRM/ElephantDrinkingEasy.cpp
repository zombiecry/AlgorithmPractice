// BEGIN CUT HERE 

// END CUT HERE
#line 5 "ElephantDrinkingEasy.cpp"
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

#ifdef __GNUC__
#define tr(container, it) \
	for (typeof(container.begin()) it = container.begin(); it != container.end();it++)

#define trCheck(container, it) \
	for (typeof(container.begin()) it = container.begin(); it != container.end();)

#else
#ifdef _MSC_VER
#define tr(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();it++)
#define trCheck(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();)

#endif
#endif
typedef std::pair <int,int> scPair2i;

const int MAX_N = 5;
int c[MAX_N][MAX_N];
#define GETINDEX(x,y)	\
	(x+y*n)
#define GETX(index)		\
	(index%n)
#define GETY(index)		\
	(index/n)



std::vector <scPair2i> points;
std::vector <int> b;
int n;
int m;
class ElephantDrinkingEasy
        { 
        public: 
		bool Portan(int dst,int src,int srcDir){
			int xDst=GETX(dst);
			int yDst=GETY(dst);
			int xSrc=GETX(src);
			int ySrc=GETY(src);
			if (srcDir==1){
				return xDst<=xSrc;
			}
			else if (srcDir==2){
				return yDst<=ySrc;
			}
			else if (srcDir==3){
				return xDst>=xSrc;
			}
			else if (srcDir==4){
				return yDst>=ySrc;
			}
			cout<<"error!"<<endl;
			return false;
		}
		bool Valid(int idx){
			if (b[idx]==0){
				return true;
			}
			int curX=GETX(idx);
			int curY=GETY(idx);
			for (int i=0;i<idx;i++){
				if (b[i]==0){
					continue;
				}
				if (Portan(i,idx,b[idx]) &&
					Portan(idx,i,b[i])){
					return false;
				}	
			}
			return true;
		}
		int CountNum(){
			int count=0;
			for (int i=0;i<m;i++){
				if (b[i]>0){
					count++;
				}
			}
			return count;
		}
        int maxElephants(vector <string> map) 
            { 
				n=map.size();
				for (int j=0;j<n;j++){
					for (int i=0;i<n;i++){
						c[j][i]=0;
					}
				}

				//x axis
				for (int j=0;j<n;j++){
					int firstW=-1;
					int lastW=-1;
					for (int i=0;i<n;i++){
						if (map[j][i]=='Y'){
							lastW=i;
							if (firstW==-1){
								firstW=i;
							}
						}
					}
					if (firstW!=-1){
						c[j][firstW]=1;
					}
					if (!c[j][lastW]){
						c[j][lastW]=3;
					}
					
				}

				//x axis
				for (int i=0;i<n;i++){
					int firstW=-1;
					int lastW=-1;
					for (int j=0;j<n;j++){
						if (map[j][i]=='Y'){
							lastW=j;
							if (firstW==-1){
								firstW=j;
							}
						}
					}
					if (firstW!=-1){
						c[firstW][i]=4;						
					}
					if (!c[lastW][i]){
						c[lastW][i]=2;
					}
				}
				int num=0;
				for (int i=0;i<n;i++){
					for (int j=0;j<n;j++){
						if (c[j][i]){
							points.push_back(scPair2i(GETINDEX(i,j),c[j][i]));
						}
					}
				}
				num=m=points.size();
				std::set <scPair2i> confPoints; 
				for (int i=0;i<m-1;i++){
					for (int j=i+1;j<m;j++){
						int ii=points[i].first;
						int ij=points[j].first;
						int diri=points[i].second;
						int dirj=points[j].second;
						if (diri%2 !=dirj%2){
							bool x1=Portan(ii,ij,dirj);
							bool x2=Portan(ij,ii,diri);
							if (x1&&x2){
								confPoints.insert(scPair2i(ii,diri));
								confPoints.insert(scPair2i(ij,dirj));
							}
						}
					}
				}
				points.clear();
				points.resize(confPoints.size());
				m=points.size();
				int i=0;
				tr(confPoints,it){
					points[i]=*it;
					i++;
				}

				/*
				int num=-1;
				b.resize(m,-1);
				int i=0;
				while (i>=0){
					b[i]++;
					if (b[i]<5){
						if (Valid(i)){
							if (i==m-1){
								num=max(num,CountNum());
							}
							else{
								i++;
							}
						}
					}
					else{
						b[i]=-1;
						i--;
					}
				}
				*/
				return num;
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NNNNN",
 "NNYYN",
 "NYNNN",
 "NNYNN",
 "NNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, maxElephants(Arg0)); }
	void test_case_1() { string Arr0[] = {"YYY",
 "YYY",
 "YYY"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, maxElephants(Arg0)); }
	void test_case_2() { string Arr0[] =  {"YNYN",
  "NNYY",
  "YYNN",
  "YYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(2, Arg1, maxElephants(Arg0)); }
	void test_case_3() { string Arr0[] =  {"YNYN",
  "YNYY",
  "YYNN",
  "YYYY"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, maxElephants(Arg0)); }
	void test_case_4() { string Arr0[] = {"YYNYN",
 "NYNNY",
 "YNYNN",
 "YYNYY",
 "YYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, maxElephants(Arg0)); }
	void test_case_5() { string Arr0[] = {"YYNYN",
 "NYNYY",
 "YNYYN",
 "YYNYY",
 "YYNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(5, Arg1, maxElephants(Arg0)); }
	void test_case_6() { string Arr0[] = {"NN",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(6, Arg1, maxElephants(Arg0)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        ElephantDrinkingEasy ___test; 
        ___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

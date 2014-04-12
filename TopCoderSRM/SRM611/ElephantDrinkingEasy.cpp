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
				return yDst>=ySrc;
			}
			else if (srcDir==3){
				return xDst>=xSrc;
			}
			else if (srcDir==4){
				return yDst<=ySrc;
			}
			cout<<"error!"<<endl;
			return false;
		}
		bool CheckConflict(int idx1,int dir1,int idx2,int dir2){
			int x1=GETX(idx1);
			int y1=GETY(idx1);
			int x2=GETX(idx2);
			int y2=GETY(idx2);
			if (idx1==idx2){
				return true;
			}
			if (dir1==dir2){
				if (dir1==1 || dir1==3){
					if (y1==y2){
						return true;
					}
				}
				if (dir1==2 || dir1==4){
					if (x1==x2){
						return true;
					}
				}
			}
			else if (dir1%2 == dir2%2){
				if (dir1%2==1){
					if (dir1==1){
						swap(dir1,dir2);
						swap(x1,x2);
						swap(y1,y2);
					}
					if (x1<=x2 && y1==y2){

						return true;
					}
				}
				else {
					if (dir1==4){
						swap(dir1,dir2);
						swap(x1,x2);
						swap(y1,y2);
					}
					if (y1<=y2 && x1==x2){

						return true;
					}
				}
			}
			else{
				if (Portan(idx1,idx2,dir2) &&
					Portan(idx2,idx1,dir1)){
						/*
						cout<<"("<<x1<<","<<y1<<","<<dir1<<")"<<"<--->("<<x2<<","<<y2<<","<<dir2<<")"<<endl;
						cout<<GETINDEX(x2,y2)<<","<<dir2<<endl;
						*/
						return true;
				}
			}

			return false;
		}
		bool Valid(int idx){
			if (b[idx]==0){
				return true;
			}
			int pointIndex=points[idx].first;
			int pointDir=points[idx].second;
			for (int i=0;i<idx;i++){
				if (b[i]==0){
					continue;
				}
				int curIndex=points[i].first;
				int curDir=points[i].second;
				if (CheckConflict(pointIndex,pointDir,curIndex,curDir)){
					

					return false;
				}
			}
			return true;
		}
		int CountNum(){
			int num=0;
			for (int i=0;i<m;i++){
				if (b[i]){
					num++;
				}
			}
			return num;
		}
        int maxElephants(vector <string> map) 
            { 
				n=map.size();
				points.clear();
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
						points.push_back(scPair2i(GETINDEX(firstW,j),1));
						points.push_back(scPair2i(GETINDEX(lastW,j) ,3));
						c[firstW][j]=1;
						c[lastW][j]=1;
					}
				}

				//y axis
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
						//if (!c[i][firstW]){
							points.push_back(scPair2i(GETINDEX(i,firstW),4));
						//}
						//if (!c[i][lastW]){
							points.push_back(scPair2i(GETINDEX(i,lastW) ,2));
						//}
						
					}
				}
				
				m=points.size();
				b.resize(m,-1);
				
				int i=0;
				int num=-1;
				//cout<<"m number: "<<m<<endl;
				if (m==0){
					num=0;
					return num;
				}
				while (i>=0){		//backtrack method
					//cout<<i<<" "<<b.size()<<endl;
					b[i]++;
					if (b[i]<2){
						if (Valid(i)){
							if (i<m-1){
								i++;
							}
							else{	//reach end
								num=max(num,CountNum());	
							}
						}
					}
					else{
						b[i]=-1;
						i--;
					}
				}
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
        //___test.run_test(-1); 
		___test.run_test(-1); 
        system("pause");
        } 
    // END CUT HERE 

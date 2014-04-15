// BEGIN CUT HERE

// END CUT HERE
#line 5 "TwoLLogo.cpp"
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
int total;

#define GETX(x) \
	(x%m)
#define GETY(x) \
	(x/m)
#define GETINDEX(x,y)   \
	(x+y*m)
typedef std::pair <int,int> scPair2i;

class TwoLLogo
{
        public:
		
		bool GetS(int x,int y,vector <string> &grid,int &sx,int &sy){
			int i=0;
			for (;i+x<m;i++){
				if (grid[y][x+i]=='#'){
					break;
				}
			}
			if (i<=1){
				return false;
			}
			sx=i-1;

			i=0;
			for (;y-i>=0;i++){
				if (grid[y-i][x]=='#'){
					break;
				}
			}
			if (i<=1){
				return false;
			}
			sy=i-1;
			return true;
		}

        long long countWays(vector <string> grid)
        {
			n=grid.size();
			m=grid[0].size();
			total=m*n;
			vector <bool> possiblePoints(total,false);
			vector <int>  sx(total,-1);
			vector <int>  sy(total,-1);
			for (int i=0;i<total;i++){
				int x=GETX(i);
				int y=GETY(i);
				if (grid[y][x]=='#'){
					possiblePoints[i]=false;
					continue;
				}
				if (!GetS(x,y,grid,sx[i],sy[i])){
					possiblePoints[i]=false;
					continue;
				}
				possiblePoints[i]=true;
			}


			long long countNum=0;
			for (int i=0;i<total-1;i++){
				if (!possiblePoints[i]){continue;}

				for (int j=i+1;j<total;j++){
					if (!possiblePoints[j]){continue;}
					int x1=GETX(i);
					int y1=GETY(i);
					int sx1=sx[i];
					int sy1=sy[i];

					int x2=GETX(j);
					int y2=GETY(j);
					int sx2=sx[j];
					int sy2=sy[j];

					if (x2<x1){
						swap(x1,x2);
						swap(y1,y2);
						swap(sx1,sx2);
						swap(sy1,sy2);
					}
					int curCount=0;
					for (int lx1=1;lx1<=sx1;lx1++){
						for (int ly2=1;ly2<=sy2;ly2++){
							if (x1==x2){
								if (y1<y2-ly2){
									curCount++;
								}
							}
							else {//x1<x2
								if (x1+lx1<x2){
									curCount++;
								}
								else {	//x1+lx1>=x2
									if (y2<y1||
										y2-ly2>y1){
										curCount++;
									}
								}
							}
						}
					}
					countNum+=curCount*sy1*sx2;
				}
			}
			return countNum;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"....",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {".##..",
 "...#.",
 ".#.#.",
 "#...#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"..#.",
 "#.#.",
 "....",
 "..#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arr0[] = {".#.#",
 "....",
 ".#.#",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 34LL; verify_case(4, Arg1, countWays(Arg0)); }
	void test_case_5() { string Arr0[] = {"##############",
 "##############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.#####.######",
 "#.#####.######",
 "#.#####.######",
 "#....##.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######......#",
 "##############"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1350LL; verify_case(5, Arg1, countWays(Arg0)); }
	void test_case_6() { string Arr0[] = {"#......",
 ".#....#",
 ".#.#...",
 "#....#.",
 ".##..#.",
 ".#.....",
 ".....#.",
 ".#.#...",
 ".#...#.",
 "..##..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2386LL; verify_case(6, Arg1, countWays(Arg0)); }
	void test_case_7() { string Arr0[] = {"...#..........................",
 "..............................",
 "..............................",
 "..................#...#.......",
 "..................#...........",
 "..............................",
 "...........#..................",
 "..............................",
 ".....#..#.....................",
 ".......................#......",
 "..................#.....#.....",
 "..............................",
 "..............................",
 "..............................",
 "..............................",
 "..#...........................",
 "..............................",
 "..............................",
 "..............................",
 "#............................#",
 "..............................",
 ".....#.........#............#.",
 "..............................",
 ".........................#....",
 ".#............................",
 ".............#................",
 "..............................",
 "..............................",
 ".......................#......",
 ".............#................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5020791386LL; verify_case(7, Arg1, countWays(Arg0)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main()
{
        TwoLLogo ___test;
        ___test.run_test(-1);
        system("pause");
        return 0;
}
// END CUT HERE

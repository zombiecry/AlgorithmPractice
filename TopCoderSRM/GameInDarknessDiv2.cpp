// BEGIN CUT HERE 

// END CUT HERE
#line 5 "GameInDarknessDiv2.cpp"
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

typedef pair<int,int> scPair;
int m,n;
class GameInDarknessDiv2
        { 
        public: 
			vector <scPair>   A;
        string check(vector <string> field, vector <string> moves) 
            { 
				int dp[2][50][50];
				memset(dp,-1,sizeof(dp));
				n=field.size();
				m=moves.size();
				scPair s,e;
				scPair bp;
				for (int i=0;i<n;i++) for (int j=0;j<field[i].length();j++){
					if (field[i][j]=='A'){
						s=scPair(i,j);
					}
					if (field[i][j]=='B'){
						bp=scPair(i,j);
					}
				}
				e=s;
				for (int i=0;i<m;i++) for (int j=0;j<moves[i].length();j++){
					switch (moves[i][j]){
					case 'U':
						e.first--;
						break;
					case 'D':
						e.first++;
						break;
					case 'R':
						e.second++;
						break;
					case 'L':
						e.second--;

					}
					A.push_back(e);
				}
				n=A.size();
				m=field.size();
				reverse(A.begin(),A.end());
				for (int j=0;j<m;j++)for (int k=0;k<field[j].length();k++){
					dp[0][j][k]=0;
					if (field[j][k]=='#'){dp[0][j][k]=1;}
				}
				dp[0][e.first][e.second]=1;
				for (int i=1;i<n;i++){
					int cur=i%2;
					int prev=(i-1)%2;
					for (int j=0;j<m;j++)for (int k=0;k<field[j].length();k++){
						dp[cur][j][k]=1;
						if (field[j][k]=='#'){continue;}
						if (scPair(j,k)==A[i]){continue;}
						if (j>0){
							if (scPair(j-1,k)!=A[i]){
								dp[cur][j][k]&=dp[prev][j-1][k];
							}
						}
						if (j<m-1){
							if (scPair(j+1,k)!=A[i]){
								dp[cur][j][k]&=dp[prev][j+1][k];
							}
						}
						if (k>0){
							if (scPair(j,k-1)!=A[i]){
								dp[cur][j][k]&=dp[prev][j][k-1];
							}
						}
						if (k<(field[j].length()-1)){
							if (scPair(j,k+1)!=A[i]){
								dp[cur][j][k]&=dp[prev][j][k+1];
							}
						}						
					}
				}
				int res= dp[(n-1)%2][bp.first][bp.second];
				if (res==1){
					return "Alice wins";
				}
				else{
					return "Bob wins";
				}
            } 
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"A.B..",
 "##.##",
 "##.##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RRDUR"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice wins"; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"A.B..",
 "##.##",
 "##..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RRRLD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bob wins"; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"###.#",
 "###..",
 "A..B#",
 "###..",
 "###.#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RR", "R", "UDD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice wins"; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"A.###",
 ".B..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"RDRRRLLLLUDUDRLURDLUD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Bob wins"; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".....",
 ".#.#.",
 "##.#.",
 "A###.",
 "B...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"D"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice wins"; verify_case(4, Arg2, check(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".#...#....#.......#....#......",
 "...###.#.#..#.#.#..###...#.#.#",
 ".#.#...#...#..#..#.....##.#...",
 "#..#.##..##..#.#..###.#....#.#",
 "..#..#..#...#...#....#..##.#..",
 "#..##..#..##.#.#.####..#.#...#",
 ".#....##.#.....#......##.#.#..",
 ".###.#...#.#.#..#.#.##...##.#.",
 ".....#.#.##..#.#..##...##...#.",
 "#.#.#...#...#.#.#...#.#.#.##.#",
 ".#..##.#..##..#.###...........",
 "..##.....####.......##.#.#.##.",
 "#....##.#.#...####.#...#.#.#..",
 "#.#.#......##.#...#..#.#..#..#",
 "..#..#.#.##...#.#..#..#..#..#.",
 ".#..#...#...#..#..#.#..#..#A#.",
 "..#..#.#.B##.##..#...#.#.##...",
 "#.#.##..#......#.#.#.#.#...#.#",
 "#.#...#.######...#.#.#.#.#.#..",
 "..#.##.#.....#.##..#...#.#.#.#",
 ".#..#..#.#.#.#.#..#.#####..#.#",
 "..#.#.##.#.#.##.#......#..#...",
 "#..#.....#.#.....#.#.##..##.#.",
 "##..###.#..#.#.#.#..##..#...##",
 "##.#...#..##.#.#..#.#..#.#.#..",
 "#..#.#.####..#..#..#..#......#",
 "..#..#.....####..#.##.#.###.#.",
 ".#..#.####.#.#..#.....#...#...",
 "..##.......#...#..####.##.#.#.",
 "#....#.#.#..#.###....#....#..#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"UURURUULLLLLLLLLLDLLLLUDLLUDDLRDDDULLDLLDDRRRRRDDU","RRUUURUULLD"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "Alice wins"; verify_case(5, Arg2, check(Arg0, Arg1)); }

// END CUT HERE
 
        };

    // BEGIN CUT HERE 
    int main()
        {
        GameInDarknessDiv2 ___test; 
        ___test.run_test(0); 
        system("pause");
        } 
    // END CUT HERE 

#include <vector>
#include <list>
#include <bitset>
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
int n,m;
class Bracket107 {
public:
	bool check_valid(string t){
		int m=t.length();
		int lb = 0;
		for (int i=0;i<m;i++){
			if (t[i]=='(') {lb++;continue;}
			lb--;
			if (lb<0) return false;
		}
		return true;
	}
	int yetanother(string s) {
		n=s.length();
		set <string> ts;
		ts.insert(s);
		for (int i=0;i<n;i++){
			string t0 = s.substr(0,i)+s.substr(i+1);
			m=t0.length();
			for (int j=0;j<=n;j++){
				string lt ="";
				if (j>0) lt= t0.substr(0,j);
				string rt ="";
				if (j<n) rt=t0.substr(j);
				string t = lt+s[i]+rt;
				if (check_valid(t)){
					ts.insert(t);
				}
			}
		}
		return ts.size()-1;
	}
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing Bracket107 (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1444565856;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Bracket107 _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string s = "(())";
				_expected = 1;
				_received = _obj.yetanother(s); break;
			}
			case 1:
			{
				string s = "(())()";
				_expected = 3;
				_received = _obj.yetanother(s); break;
			}
			case 2:
			{
				string s = "()()()";
				_expected = 3;
				_received = _obj.yetanother(s); break;
			}
			case 3:
			{
				string s = "(((())))";
				_expected = 5;
				_received = _obj.yetanother(s); break;
			}
			case 4:
			{
				string s = "((())())";
				_expected = 9;
				_received = _obj.yetanother(s); break;
			}
			/*case 5:
			{
				string s = ;
				_expected = ;
				_received = _obj.yetanother(s); break;
			}*/
			/*case 6:
			{
				string s = ;
				_expected = ;
				_received = _obj.yetanother(s); break;
			}*/
			/*case 7:
			{
				string s = ;
				_expected = ;
				_received = _obj.yetanother(s); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE


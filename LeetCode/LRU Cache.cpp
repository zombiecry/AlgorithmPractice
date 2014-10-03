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
#include <fstream>
using namespace std;
typedef pair<int,int> scpair;
class LRUCache{
public:

	map <int,int> c;
	map <int,int> u;
	std::set <scpair,less<scpair>>  s;
	int           cap;
	long long unsigned ops;
	LRUCache(int capacity) {
		cap=capacity;
		ops=0;
	}
	int get(int key) {
		if (c.find(key)!=c.end()){
			ops++;
			int old=u[key];
			u[key]=ops;
			s.erase(scpair(old,key));
			s.insert(scpair(ops,key));
			return c[key];
		}
		return -1;

	}

	void set(int key, int value) {
		ops++;
		if (c.find(key)!=c.end()){
			c[key]=value;
			int old=u[key];
			u[key]=ops;
			s.erase(scpair(old,key));
			s.insert(scpair(ops,key));
			return;
		}
		if (c.size()==cap){ //first delete
			scpair t=*s.begin();
			s.erase(s.begin());
			c.erase(c.find(t.second));
			u.erase(u.find(t.second));
		}
		c[key]=value;
		u[key]=ops;
		s.insert(scpair(ops,key));
	}
};
int main (){
	LRUCache *lru=new LRUCache(1);
	return 0;
}
/*
ID: yezhiyo1
PROG: shopping
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
ifstream fin("shopping.in");
ofstream fout("shopping.out");

int s;
struct Offer{
	int n;
	std::vector <int> c;
	std::vector <int> k;
	int p;
};
std::vector <Offer> offers;

struct Remain{
	std::vector <int> buyC;
	std::vector <int> buyK;
};

int b;
std::vector <int> buyC;
std::vector <int> buyK;

const unsigned int MAX_PRICE=0xffffffff;
struct State{
	Remain   rem;
	int      si;
	unsigned int minCost;
};

int main (){

	
	

	return 0;
}
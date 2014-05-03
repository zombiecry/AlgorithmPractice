#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;
#if 0
ifstream fin("reorder.in");
ofstream fout("reorder.out");
#define cin fin
#define cout fout
#endif
#ifdef __GNUC__
#define tr(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();it++)

#define trCheck(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();)

#else
#ifdef _MSC_VER
#define tr(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();it++)
#define trCheck(container, it) \
	for (decltype(container.begin()) it = container.begin(); it != container.end();)

#endif
#endif
typedef pair<int,int> scPair2i;
typedef pair<char,int> scPair;
string line;
const string invStr="<invalid input string>";

string Reorder(){
	std::map <char,int> cMap;
	for (int i=0;i<line.length();i++){
		char ch=line[i];
		if ((ch>='0' && ch<='9')||(ch>='a' &&ch<='z')){
			if (cMap.count(ch)>0){
				cMap[ch]++;
			}
			else{
				cMap[ch]=1;
			}
		}
		else{
			return invStr;
		}
	}
	string res;
	string temp;
	do{
		temp="";
		for (map<char,int>::iterator it = cMap.begin(); it != cMap.end();it++){
			if (it->second){
				temp+=it->first;
				it->second--;
			}
		}
		res+=temp;
	}while(temp.length());
	return res;
}


int main (){
	while (getline(cin,line)){
		if (line.length()){
			cout<<Reorder()<<endl;
		}
	}
	return 0;
}
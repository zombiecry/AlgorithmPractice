#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;
int N;
int main (){
	cin>>N;
	char op;
	double a;
	double b;
	std::vector <double> res;
	for (int i=0;i<N;i++){
		cin>>a>>op>>b;
		if (a>=-10000 && a<=10000){
			switch (op){
			case '+':
				res.push_back(a+b);
				break;
			case '-':
				res.push_back(a-b);
				break;
			case '*':
				res.push_back(a*b);
				break;
			case '/':
				res.push_back(a/b);
				break;
			}
		}
	}

	double minDelta=1e20;
	int    minIndex;
	for (int i=0;i<res.size();i++){
		double curDelta=double(res[i]-9);
		if (curDelta<0){
			curDelta=curDelta*(-1);
		}
		if (curDelta<minDelta){
			minDelta=curDelta;
			minIndex=i+1;
		}
	}
	cout<<minIndex<<endl;
	return 0;
}
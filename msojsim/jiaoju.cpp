#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <iomanip>      // std::setprecision
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;

#define DEBUG_FLAG 1
#if DEBUG_FLAG
ifstream fin("jiaoju.in");
ofstream fout("jiaoju.out");
#define cin fin
#define cout fout
#endif
//
typedef long long ll;
#define tr(container,it)		\
	for (it=container.begin();it!=container.end();it++)
typedef std::pair <int,int> scPair2i;
int T;
double fl;
string flUnit;
string flStr;
double ccd;
string ccdUnit;
string ccdStr;
double imWidth;
string imWStr;

double focal;
double UnitFactor(string unit){
	double res;
	if (unit=="m"){
		res=1000;
	}
	else if (unit=="dm"){
		res=100;
	}
	else if (unit=="cm"){
		res=10;
	}
	else if (unit=="mm"){
		res=1;
	}
	else if (unit=="um"){
		res=0.001;
	}
	else if (unit=="nm"){
		res=1e-6;
	}
	return res;
}

void GetNumAndUnit(string str,double &num,string &unit){
	int i=0;
	for (;i<str.length();i++){
		if (str[i]=='.' || ((str[i]<='9') && (str[i]>='0'))){

		}
		else{
			break;
		}
	}
	string numStr=str.substr(0,i);
	string unitStr=str.substr(i);
	istringstream sin(numStr);
	sin>>num;
	unit=unitStr;
}


void CalcFocal(){
	fl=fl*UnitFactor(flUnit);
	ccd=ccd*UnitFactor(ccdUnit);
	focal=(imWidth*fl)/ccd;
}
int main(){
	cin>>T;
	for (int i=0;i<T;i++){
		//cin>>fl>>flUnit>>ccd>>ccdUnit>>imWidth;
		cin>>flStr>>ccdStr>>imWStr;
		GetNumAndUnit(flStr,fl,flUnit);
		GetNumAndUnit(ccdStr,ccd,ccdUnit);
		GetNumAndUnit(imWStr,imWidth,imWStr);
		CalcFocal();
		cout<<"Case "<<i+1<<": "<<setiosflags(ios::fixed)<<setprecision(2)<<focal<<"px"<<endl;
	}




	return 0;
}
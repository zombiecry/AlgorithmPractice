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

std::map    <string,int> c;
struct Offer{
	std::vector <int> codes;
	std::vector <int> nums;
};
std::vector <Offer>      offers;
std::vector <string>     sOffers;
std::vector <int>        orgPOffers;
std::vector <int>		 pOffers;

std::vector <int>        reqCodes;
std::vector <int>        reqNums;
std::vector <int>        reqPrices;
int s;
int b;

int CalcSum(string reqs){
	int sum=0;
	for (int i=0;i<b;i++){
		sum+=(reqs[i]-'0')*reqPrices[i];
	}
	return sum;
}

bool Minus(string &result,string rem,string offer){
	result=rem;
	for (int i=0;i<b;i++){
		if (rem[i]<offer[i]){
			return false;
		}
		result[i]='0'+(rem[i]-offer[i]);
	}
	return true;
}

bool Valid(string temp){
	for (int i=0;i<b;i++){
		if (temp[i]<'0'){
			return false;
		}
	}
	return true;
}

string NextStr(string cur){
	int i=0;
	while (i<5){
		cur[i]++;
		if (cur[i]>='6'){
			cur[i]-=6;
		}
		else{
			break;
		}
		i++;
	}
	return cur;
}

int main (){
	fin>>s;
	offers.resize(s);
	orgPOffers.resize(s);
	for (int i=0;i<s;i++){
		int n;
		fin>>n;
		offers[i].codes.resize(n);
		offers[i].nums.resize(n);
		for (int j=0;j<n;j++){
			fin>>offers[i].codes[j]>>offers[i].nums[j];
		}
		fin>>orgPOffers[i];
	}

	fin>>b;
	reqCodes.resize(b);
	reqNums.resize(b);
	reqPrices.resize(b);
	string reqStr;
	reqStr.resize(b);
	for (int i=0;i<b;i++){
		fin>>reqCodes[i]>>reqNums[i]>>reqPrices[i];
		reqStr[i]='0'+reqNums[i];
	}

	for (int i=0;i<s;i++){
		string oStr;
		oStr.resize(reqCodes.size(),'0');
		bool validFlag=true;
		for (int j=0;j<offers[i].codes.size();j++){
			bool findFlag=false;
			for (int k=0;k<b;k++){
				if (offers[i].codes[j]==reqCodes[k]){
					oStr[k]='0'+offers[i].nums[j];
					findFlag=true;
					break;
				}
			}
			if (!findFlag){
				validFlag=false;
				break;
			}
		}
		if (validFlag){				
			sOffers.push_back(oStr);
			pOffers.push_back(orgPOffers[i]);
		}
		else{			
			s--;
		}
	}

	string j;
	j.resize(b);
	for (int i=0;i<b;i++){
		j[i]='0';
	}
	c[j]=0;
	j=NextStr(j);
	while (true){
		c[j]=CalcSum(j);
		for (int i=0;i<s;i++){
			string temp;
			if (Minus(temp,j,sOffers[i])){
				c[j]=std::min(c[j],c[temp]+pOffers[i]);
			}
		}
		if (j==reqStr){
			break;
		}
		j=NextStr(j);
	}
	fout<<c[j]<<endl;

	return 0;
}
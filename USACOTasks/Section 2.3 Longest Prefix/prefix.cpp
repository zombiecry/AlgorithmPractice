/*
ID: yezhiyo1
PROG: prefix
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <memory.h>
#include <vector>
using namespace std;
string s;
vector <string> prims;

int main (){
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");
	string temp;
	fin>>temp;
	while (temp!="."){
		prims.push_back(temp);
		fin>>temp;
	}
	while (fin){
		string line;
		fin>>line;
		s+=line;
	}
	vector <int> c;
	int sLength=s.length();
	c.resize(sLength,0);
	for (int i=0;i<prims.size();i++){
		if (s.substr(sLength-1,1)==prims[i]){
			c[sLength-1]=1;
			break;
		}
	}
	for (int i=sLength-2;i>=0;i--){
		for (int j=0;j<prims.size();j++){
			string a=prims[j];
			if (i+a.length()<=sLength-1){
				if (s.substr(i,a.length())==a){
					c[i]=max<int>(c[i],c[i+a.length()]+a.length());
				}
			}
		}
	}
	fout<<c[0]<<endl;
	return 0;
}
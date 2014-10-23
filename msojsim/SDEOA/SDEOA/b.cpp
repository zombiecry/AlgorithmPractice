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

ifstream fin("b.in");
ofstream fout("b.out");
#define cin fin
#define cout fout

int N;
int n,m;
struct Call{
	string fn;
	string ts;
	int	   op;
};
vector <Call> cs;

vector<vector<int> > g;
vector<int>			sv;
vector<int>			ev;
map <string,int>    cm;
map <string,int>    im;
map <int,string>    dm;

typedef map<string,int>::iterator sciter;
void Change(string &t,vector<int> &tv){
	string hs=t.substr(0,2);
	string ms=t.substr(3,2);
	string ss=t.substr(6,2);
	tv[2]=atoi(hs.c_str());
	tv[1]=atoi(ms.c_str());
	tv[0]=atoi(ss.c_str());
}
void Change1(string &t,vector<int> &tv){
	int count=0;
	if (tv[2]<10){
		t[count++]='0';
		t[count++]=tv[2]+'0';
	}
	else{
		t[count++]=tv[2]/10+'0';
		t[count++]=tv[2]%10+'0';
	}
	t[count++]=':';
	if (tv[1]<10){
		t[count++]='0';
		t[count++]=tv[1]+'0';
	}
	else{
		t[count++]=tv[1]/10+'0';
		t[count++]=tv[1]%10+'0';
	}
	t[count++]=':';
	if (tv[0]<10){
		t[count++]='0';
		t[count++]=tv[0]+'0';
	}
	else{
		t[count++]=tv[0]/10+'0';
		t[count++]=tv[0]%10+'0';
	}
}
string Duration(int u){
	string start=cs[sv[u]].ts;
	string end=cs[ev[u]].ts;
	vector<int> t1(3);
	vector<int> t2(3);
	Change(start,t1);
	Change(end,t2);
	int up=0;
	vector<int> t3(3);
	for(int i=0;i<3;i++){
		t3[i]=t2[i]-t1[i]+up;
		if(t3[i]<0) {
			up=-1;
			t3[i]+=60;
		}
	}
	string res="  :  :  ";
	Change1(res,t3);
	return res;
}
void DFS(int u){
	cout<<dm[u]<<" "<<Duration(u)<<endl;
	for(int i=0;i<g[u].size();i++) DFS(g[u][i]);	//no cycle(every func once)
}
bool MyCompare(const Call &c1,const Call &c2){
	return c1.ts<=c2.ts;
}
bool Solve(){
	g.resize(cm.size(),vector<int>());
	sv.resize(cm.size());
	ev.resize(cm.size());
	im=cm;
	int i=0;
	for(sciter it=im.begin();it!=im.end();it++,i++){
		it->second=i;
		dm[i]=it->first;
	}
	//check valid
	stack<string> st;
	string mints="99:99:99";
	string minfn;
	sort(cs.begin(),cs.end(),MyCompare);
	for(int i=0;i<cs.size();i++){
		Call &cur=cs[i];
		if (cm[cur.fn]>1) return false;
		if (cur.ts<mints) {
			mints=cur.ts;
			minfn=cur.fn;
		}
		if (cm[cur.fn]==0) {
			if(cur.op!=0) return false;
			cm[cur.fn]=1;
			//build call edge
			if (!st.empty()) {
				int id=im[st.top()];
				g[id].push_back(im[cur.fn]);
			}
			st.push(cur.fn);
			sv[im[cur.fn]]=i;
			continue;
		}
		if (cm[cur.fn]==1){
			if(cur.op!=1) return false;
			cm[cur.fn]=2;
			if (!st.empty()){
				if (st.top()!=cur.fn) return false;
				st.pop();
			}
			//close
			ev[im[cur.fn]]=i;
			continue;
		}
		
	}
	if(!st.empty()) return false;
	DFS(im[minfn]);
	return true;
}


int main(){
	cin>>N;
	for(int i=0;i<N;i++){
		Call c;
		cin>>c.fn>>c.ts;
		string act;
		cin>>act;
		if(act=="START") c.op=0;
		else c.op=1;
		cs.push_back(c);
		cm[c.fn]=0;
	}
	if(!Solve()){
		cout<<"Incorrect performance log"<<endl;
	}
	return 0;
}
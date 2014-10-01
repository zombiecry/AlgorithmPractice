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
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef unordered_set<string> scset;
typedef unordered_set<string>::iterator sciter;

const int INF=9999;
class Solution {
public:
	int m,n;
	vector<vector <int>> g;
	vector <string>      elems;
	vector <int>		 pres;
	vector <int>		 d;
	int					 len;
	vector<vector<string>> tot;
	bool CheckCon(string a,string b){
		int res=0;
		for (int i=0;i<a.length();i++){
			if (a[i]!=b[i]){
				res++;
				if (res>1){return false;}
			}
		}
		return true;
	}
	void Solve(int u){
		if (d[u]==len){	//reach the end
			if (u==1){	//just find it
				tot.push_back(vector<string>());
				int count=tot.size()-1;
				for (int i=u;i!=-1;i=pres[i]){
					tot[count].push_back(elems[i]);
				}
				reverse(tot[count].begin(),tot[count].end());
			}
			return;
		}
		for (int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if (d[v]==d[u]+1){
				pres[v]=u;
				Solve(v);
			}
		}
	}
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		n=dict.size()+2;
		g.resize(n,vector<int>());
		elems.resize(n);
		elems[0]=start;
		elems[1]=end;
		int count=2;
		for (sciter it=dict.begin();it!=dict.end();it++){
			elems[count++]=*it;
		}
		for (int i=0;i<n-1;i++){
			for (int j=i+1;j<n;j++){
				if (CheckCon(elems[i],elems[j])){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
		list <int> que;
		que.push_back(0);
		d.resize(n,INF);
		d[0]=0;
		while (!que.empty()){
			int u=que.front();
			que.pop_front();
			for (int i=0;i<g[u].size();i++){
				int v=g[u][i];
				if (d[v]==INF){
					d[v]=d[u]+1;
					que.push_back(v);
				}
			}
		}
		len=d[1];
		pres.resize(n,-1);
		Solve(0);
		//cout<<"len: "<<d[1]<<endl;
		return tot;
	}
};
int main (){
	Solution *sol=new Solution;
	string start="nape";
	string end="mild";
	unordered_set<string> dict;
	string ss[]={"hot","dot","dog","lot","log"};
	string ss1[]={"dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"};
	dict.insert(ss1,ss1+sizeof(ss1)/sizeof(ss1[0]));
	vector<vector<string>> res=sol->findLadders(start,end,dict);
	for (int i=0;i<res.size();i++){
		cout<<"[";
		for (int j=0;j<res[i].size();j++){
			cout<<"\""<<res[i][j]<<"\",";
		}
		cout<<"]"<<endl;
	}
	system("pause");
	return 0;
}

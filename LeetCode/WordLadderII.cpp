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
typedef pair<int,int> scpair;

const int INF=9999;
class Solution {
public:
	int m,n;
	vector<vector<int>>			g;
	unordered_map <string,int>  cm;
	vector <string>				elems;
	vector<vector<string>>		tot;
	string						end;
	vector <int>				pres;
	vector <bool>				vis;
	int							minL;
	vector <int>				levels;
	void DFS(int u,int l){
		if (l>minL){return;}
		if (elems[u]==elems[1]){
			tot.push_back(vector<string>());
			vector <string> &cur=tot[tot.size()-1];
			for (int i=u;i!=-1;i=pres[i]){
				cur.push_back(elems[i]);
			}
			reverse(cur.begin(),cur.end());
			return;
		}
		for (int i=0;i<g[u].size();i++){
			int v=g[u][i];
			pres[v]=u;
			DFS(v,l+1);
		}
	}
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		m=start.length();
		sciter it=dict.find(start);
		if (it!=dict.end()){dict.erase(it);}
		it=dict.find(end);
		if (it!=dict.end()){dict.erase(it);}
		n=dict.size()+2;
		g.resize(n,vector<int>());
		elems.resize(n);
		elems[0]=start;
		elems[1]=end;
		cm[start]=0;
		cm[end]=1;
		int count=2;
		for (sciter it=dict.begin();it!=dict.end();it++){
			elems[count]=*it;
			cm[*it]=count;
			count++;
		}
		list <int> que;
		que.push_back(0);
		dict.insert(end);
		levels.resize(n,INF);
		levels[0]=0;
		while(!que.empty()){
			int u=que.front();
			que.pop_front();
			string us=elems[u];
			if (levels[u]>=levels[1]){continue;}	//not longer, we just need the shortest path
			for (int i=0;i<m;i++){		//all possible changes from cur node
				for (int j=0;j<26;j++){
					string us=elems[u];
					char nc=j+'a';
					if (nc==us[i]){continue;}
					string vs=us;
					vs[i]=nc;
					sciter it=dict.find(vs);
					if (it!=dict.end()){		//we have a edge from u->v
						int v=cm[vs];
						if (levels[v]>levels[u]){	//ensure a DAG is constructed
							g[u].push_back(v);
						}
						if (levels[v]!=INF){	//ensure not repeat
							continue;
						}
						levels[v]=levels[u]+1;	//node's not repeat, the level is unique for every word
						que.push_back(v);
					}
				}
			}
		}
		minL=levels[1];
		vis.assign(n,false);
		pres.resize(n,-1);
		DFS(0,0);
		return tot;
	}
};
int main (){
	Solution *sol=new Solution;
	//string start="nape";
	//string end="mild";
	//string start="hit";
	//string end="cog";
	//string start="hot";
	//string end="dog";
	string start="red";
	string end="tax";
	unordered_set<string> dict;
	string ss[]={"hot","dot","dog","lot","log"};
	string ss1[]={"dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"};
	string ss2[]={"hot","cog","dog","tot","hog","hop","pot","dot"};
	string ss3[]={"ted","tex","red","tax","tad","den","rex","pee"};
	//dict.insert(ss,ss+sizeof(ss)/sizeof(ss[0]));
	//dict.insert(ss1,ss1+sizeof(ss1)/sizeof(ss1[0]));
	//dict.insert(ss2,ss2+sizeof(ss2)/sizeof(ss2[0]));
	dict.insert(ss3,ss3+sizeof(ss3)/sizeof(ss3[0]));
	vector<vector<string>> res=sol->findLadders(start,end,dict);
	for (int i=0;i<res.size();i++){
		cout<<"[";
		for (int j=0;j<res[i].size();j++){
			cout<<"\""<<res[i][j]<<"\",";
		}
		cout<<"]"<<endl;
	}
	return 0;
}

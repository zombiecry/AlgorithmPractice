#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream fin("C-large.in");
ofstream fout("c1.out");
#define cin fin
#define cout fout
int aaa(int N,int k, const vector<int> &vec)
{
	if(N<=2)
		return N;
	vector<bool> tmp(N,false);
	bool adjacent = false;
	for(int i=0;i<N-2;i++){
		if(tmp[i])
			continue;
		for(int j=i+1;j<N-1;j=j+3){
			if(tmp[j])
				continue;
			if(vec[j]-vec[i]==k){
				for(int x=j+1;x<N;x=x+3){
					if(tmp[x])
						continue;
					if(vec[x]-vec[j]==k){
						tmp[i] = tmp[j] = tmp[x] = true;
						if(!adjacent && x-j==1 && j-i==1)
							adjacent = true;
						break;
					}
				}
				if(tmp[j])
					break;
			}
		}
	}
	if(!adjacent)
		return N;

	int count = 0;
	for(int y=0;y<N;y++){
		if(!tmp[y])
			count ++;
	}
	return count;
}


int main(){
	int T = 1;
	fin>> T;
	for(int t=0;t<T;t++){
		int N = 6;
		int k = 1;
		fin>>N>>k;
		vector<int> tt;
		for(int i = 0;i<N;i++){
			int num = i/2;
			fin>>num;
			tt.push_back(num);		
		}
		//cout<<aaa(N,k,tt)<<endl;
		fout<<"Case #"<<t+1<<": "<<aaa(N,k,tt)<<endl;
	}
	return 0;
}

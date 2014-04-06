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


int n;
std::vector <int> arr;
bool find(std::vector<int> &subSeq,int start,int len){
	for (int i=start;i<n;i++){
		bool findFlag=true;
		for (int j=0;j<len;j++){
			if (i+j<=n-1){
				if (arr[i+j]!=subSeq[j]){
					findFlag=false;
					break;
				}
			}
			else{
				findFlag=false;
				break;
			}
		}
		if (findFlag){
			return true;
		}
	}
	return false;
}


bool findLen(int len){
	std::vector <int> curSeq;
	curSeq.resize(len);

	for (int i=0;i+len-1<=n-1;i++){
		for (int j=0;j<len;j++){
			curSeq[j]=arr[i+j];
		}
		if (find(curSeq,i+len,len)){
			return true;
		}
	}
	return false;
}

int main (){
	cin>>n;
	arr.resize(n);
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	int i=n/2;
	for (;i>=1;i--){
		if (findLen(i)){
			break;
		}	
	}
	cout<<i;
	return 0;
}
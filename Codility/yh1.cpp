#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char *argv[])
{
	int a[]={0,1,2,3,4};
	vector<int> v(a,a+5);
	int res=0;
	do{
		bool ok=true;
		for (int i=0;i<5;i++ ){
			if(v[i]==i)
			{
				ok=false;
				break;
			}
		}
		res+=ok;
	}while (next_permutation(v.begin(),v.end()));
	cout<<res<<endl;
	return 0;
}

#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
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

#define DEBUG_FLAG 0
#if DEBUG_FLAG
ifstream fin("huo.in");
ofstream fout("huo.out");
#define cin fin
#define cout fout
#endif
//
typedef long long ll;
#define tr(container,it)		\
	for (it=container.begin();it!=container.end();it++)
typedef std::pair <int,int> scPair2i;
int T;
int N;
vector <double> x;
vector <double> y;

void CalcLine(double &a,double &b){
	double sumx=0;
	double sumy=0;
	double sumxsquare=0;
	double sumxy=0;
	int i;
	for (i=0;i<N;i++)
	{
		sumx+=x[i];
		sumy+=y[i];
		sumxsquare+=x[i]*x[i];
		sumxy+=x[i]*y[i];
	}
	a=(i*sumxy-sumx*sumy)/(sumxsquare*i-sumx*sumx);
	b=(sumx*sumxy-sumxsquare*sumy)/(sumx*sumx-sumxsquare*i);

}

int main (){
	cin>>T;
	for (int i=0;i<T;i++){
		cin>>N;
		x.resize(N);
		y.resize(N);
		for (int j=0;j<N;j++){
			cin>>x[j]>>y[j];
		}
		double a,b;
		CalcLine(a,b);

		if (fabs(a)<1e-6){
			double sum=0;
			for (int j=0;j<N;j++){
				sum+=x[j];
			}
			sum/=N;
			cout<<sum<<endl;
		}
		else{
			cout<<-b/a<<endl;
		}
		
	}
	return 0;
}
#include <iostream>
#include <exception>

using namespace std;
 
class A{
	char b;
	double a;
};

class B{
	char a;
	A aa;
};


int main (){
	cout<<sizeof(B)<<endl;
	system("pause");
	return 0;
}
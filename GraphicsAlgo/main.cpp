#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

class X{

};

class X1:public X{};
class X2:public X{};
class A:public X1,public X2{};

int main (){
	cout<<sizeof(A)<<endl;
	system("pause");
	return 0;
}
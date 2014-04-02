#include <iostream>
#include <vector>
using namespace std;
vector <int> theArray;
//split should subject to 3 cond during swap
//1> the start must be mid num
//2> (start,i] < x and [j,end) >x
//3> every time throw a[j] to a[i] and i++ until a[j]>x
int Split(int start,int mid,int end){
	std::swap(theArray[start],theArray[mid]);		//put the mid at start, we must find it later.
	int x=theArray[start];
	int i=start;
	int j=end-1;
	for (;j>i;j--){
		while (theArray[j]<x && j>i){
			i++;
			std::swap(theArray[i],theArray[j]);
		}
	}
	std::swap(theArray[i],theArray[start]);
	return i;
}
//sort [start,end)
//the QSort must s.t.:
//1> each of two section must smaller than org
void QSort(int start,int end){
	if (end-start<=1){
		return;
	}
	int mid=(start+end)/2;
	int pos=Split(start,mid,end);
	QSort(start,pos);
	QSort(pos+1,end);
}


int main (){
	theArray.resize(10);
	for (int i=0;i<10;i++){
		theArray[i]=rand()%101;
	}
	QSort(0,theArray.size());
	for (int i=0;i<theArray.size();i++){
		cout<<theArray[i]<<" ,";
	}
	cout<<endl;
	system("pause");
	return 0;
}
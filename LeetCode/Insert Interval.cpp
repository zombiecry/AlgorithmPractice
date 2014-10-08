/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
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
 struct Interval {
	     int start;
	     int end;
	     Interval() : start(0), end(0) {}
	     Interval(int s, int e) : start(s), end(e) {}
	};
 class Solution {
 public:
	 int n,m;
	 vector <int> v;
	 bool Inter(Interval &t1,Interval &t2){
		 if (t1.start>=t2.start && t1.start<=t2.end){
			 return true;
		 }
		 if (t1.end>=t2.start && t1.end<=t2.end){
			 return true;
		 }
		 return false;
	 }
	 vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		 m=intervals.size();

		 vector<Interval> &a=intervals;
		 int l=newInterval.start;
		 int r=newInterval.end;
		 vector <Interval> res;
		 if (m==0) {
			 res.push_back(newInterval);
			 return res;
		 }
		 if (r<a[0].start){
			 res.push_back(newInterval);
			 for (int i=0;i<m;i++){res.push_back(a[i]);}
			 return res;
		 }
		 if (l>a[m-1].end){
			 res=a;
			 res.push_back(newInterval);
			 return res;
		 }
		 bool enter=false;
		 for (int i=0;i<m;i++){
			 if (Inter(a[i],newInterval)){
				 enter=true;
				 l=min(l,a[i].start);
				 r=max(r,a[i].end);
			 }
			 else{
				 if (enter){
					 res.push_back(Interval(l,r));
					 enter=false;
					 res.push_back(a[i]);
				 }
				 else{
					 res.push_back(a[i]);
					 if (i<m-1){
						 if (l>a[i].end && r<a[i+1].start){
							 res.push_back(newInterval);
						 }
					 }
				 }
			 }
		 }
		 if (enter) res.push_back(Interval(l,r));
		 return res;
	 }
 };

int main (){
	//int a[]={1,2,3,5,6,7,8,10,12,16};
	int a[]={1,3,6,9};
	vector <Interval> b;
	for (int i=0;i<sizeof(a)/sizeof(a[0]);i+=2){
		Interval t(a[i],a[i+1]);
		b.push_back(t);
	}
	Solution *sol=new Solution;
	vector<Interval> ret=sol->insert(b,Interval(2,5));
	for (int i=0;i<ret.size();i++){
		cout<<ret[i].start<<","<<ret[i].end<<endl;
	}
	system("pause");
	return 0;
}
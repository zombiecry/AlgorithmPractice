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
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	int n,m;
	vector<ListNode *> lists;
	void Merge(int a,int b){
		ListNode *h1=lists[a];
		ListNode *h2=lists[b];
		if (h1==NULL){
			lists[a]=h2;
			return;
		}
		if (h1==h2){
			return;
		}
		ListNode *p,*q,*lp,*h;
		lp=NULL;
		p=h1;
		q=h2;
		h=h1;
		while(q!=NULL && p!=NULL){
			if (p->val>q->val){
				if (lp!=NULL) {
					lp->next=q;
				}
				else{
					h=q;
				}
				ListNode *qq=q;
				q=q->next;
				qq->next=p;
				lp=qq;
				continue;
			}
			if (lp==NULL){
				h=p;
			}
			lp=p;
			p=p->next;
		}
		if (p==NULL) lp->next=q;
		lists[a]=h;
	}
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		n=lists.size();
		if (n==0){return NULL;}
		this->lists=lists;
		int step=2;
		while(step<=2*(n-1)){
			for (int i=0;i<n;i+=step){
				int b=i+step/2;
				if (b>=n){
					break;
				}
				Merge(i,b);
			}
			step*=2;
		}
		return this->lists[0];
	}
};

ListNode* ConstList(int a[],int n){
	ListNode *head=NULL;
	for (int i=n-1;i>=0;i--){
		ListNode *cur=new ListNode(a[i]);
		cur->next=head;
		head=cur;
	}
	return head;
}

int main (){
	Solution *sol=new Solution;
	vector<ListNode *> lists;
	/*
	int a[]={-9,-7,-7};
	int b[]={-6,-4,-1,1};
	int c[]={-6,-5,-2,0,0,1,2};
	int d[]={-9,-8,-6,-5,-4,1,2,4};
	int e[]={-10};
	int f[]={-5,2,3};
	
	lists.push_back(ConstList(a,sizeof(a)/sizeof(a[0])));
	lists.push_back(ConstList(b,sizeof(b)/sizeof(b[0])));
	lists.push_back(ConstList(c,sizeof(c)/sizeof(c[0])));
	lists.push_back(ConstList(d,sizeof(d)/sizeof(d[0])));
	lists.push_back(ConstList(e,sizeof(e)/sizeof(e[0])));
	lists.push_back(ConstList(f,sizeof(f)/sizeof(f[0])));
	*/
	int a[]={1,2,2};
	int b[]={1,1,2};

	lists.push_back(ConstList(a,sizeof(a)/sizeof(a[0])));
	lists.push_back(ConstList(b,sizeof(b)/sizeof(b[0])));
	ListNode *p=sol->mergeKLists(lists);
	while(p!=NULL){
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
	system("pause");
	return 0;
}
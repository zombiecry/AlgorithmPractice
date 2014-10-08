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
typedef pair<ListNode *,ListNode *> scpair;
class Solution {
public:
	int n,m;
	scpair Merge(ListNode *hh,ListNode *ee,ListNode *h1,ListNode *t1){
		ListNode *p=h1;
		ListNode *lp=hh;
		ListNode *q=t1->next;
		scpair res=scpair(h1,t1);
		if (h1==t1){
			while(q!=ee){
				if (p->val<=q->val) break;
				if (lp!=NULL) lp->next=q;
				p->next=q->next;
				q->next=p;
				if (lp==hh) res.first=q;
				lp=q;
				q=p->next;
			}
			p=res.first;
			while(p!=ee){
				res.second=p;
				p=p->next;
			}
			return res;
		}
		res.first=h1;
		while(q!=ee && p!=ee && p!=q){
			if (p->val<q->val){
				lp=p;
				p=p->next;
			}
			else{
				t1->next=q->next;
				q->next=p;
				if (lp!=NULL) lp->next=q;
				if (lp==hh) res.first=q;
				lp=q;
				q=t1->next;
			}
		}
		p=res.first;
		while(p!=ee){
			res.second=p;
			p=p->next;
		}
		return res;
	}
	scpair MSort(ListNode *hh,ListNode *ee,ListNode *h,ListNode *t,int num){
		if (h==t){return scpair(h,t);}
		ListNode *h1=h;
		ListNode *t1=h;
		int count=1;
		while(count<num/2){
			t1=t1->next;
			count++;
		}
		ListNode *h2=t1->next;
		ListNode *t2=t;
		scpair l=MSort(hh,h2,h1,t1,count);
		scpair r=MSort(l.second,ee,h2,t2,num-count);
		scpair res=Merge(hh,ee,l.first,l.second);
		return res;
	}
	ListNode *sortList(ListNode *head) {
		if (head==NULL){return NULL;}
		ListNode *p=head;
		ListNode *q=p;
		n=1;
		while (p->next!=NULL){
			q=p;
			p=p->next;
			n++;
		}
		if (p==q){return head;}
		scpair res=MSort(NULL,NULL,head,p,n);
		return res.first;
	}
};

int main (){
	int a[]={1,2,3,4};
	ListNode *head=NULL;
	int n=sizeof(a)/sizeof(a[0]);
	for (int i=n-1;i>=0;i--){
		ListNode *cur=new ListNode(a[i]);
		cur->next=head;
		head=cur;
	}
	Solution *sol=new Solution;
	ListNode *p=sol->sortList(head);
	while(p){
		cout<<p->val<<" ";
		p=p->next;
	}
	cout<<endl;
	system("pause");
	return 0;
}
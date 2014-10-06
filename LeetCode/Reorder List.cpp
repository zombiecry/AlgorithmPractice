/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	void reorderList(ListNode *head) {
		if (head==NULL){return;}
		stack <ListNode *> st;
		ListNode *p=head;
		while(p!=NULL){
			st.push(p);
			p=p->next;
		}
		if (st.size()==1){return;}
		p=head;
		ListNode *q=st.top();
		st.pop();
		while(p->next!=q){
			ListNode *r=p->next;
			p->next=q;
			q->next=r;
			p=r;
			if (p->next==q){
				p->next=NULL;
				break;
			}
			q=st.top();
			st.pop();
		}
	}
};

int main (){
	Solution *sol=new Solution;
	ListNode *l0=new ListNode(1);
	ListNode *l1=new ListNode(2);
	ListNode *l2=new ListNode(3);
	l0->next=l1;
	l1->next=l2;
	sol->reorderList(l0);
	ListNode *p=l0;
	while (p){
		cout<<p->val<<" "<<endl;
		p=p->next;
	}
	system("pause");
	return 0;
}
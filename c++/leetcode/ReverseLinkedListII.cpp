/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *pstart,*pi,*pj,*pend;
		ListNode mystart(0),myend(0);
		//int count=1;
		if (head->next==NULL || m==n)
			return head;

		//add head,tail
		pstart=&mystart;
		mystart.next=head;
		pend=head;
		while (pend->next){
			//count++;
			pend=pend->next;
		}
		pend->next=&myend;
		m++;n++;

		//find pstart
		for (int i=2;i<m;i++){
			if (pstart->next!=NULL)
				pstart=pstart->next;
		}

		//init pi,pj,pend;
		pi=pstart;
		if (pi->next!=&myend)
			pj=pi->next;
		if (pj->next!=&myend)
			pend=pj->next;
		
		pj->next=NULL;
		for (int i=m;i<n;i++){
			pi=pj;
			pj=pend;
			pend=pend->next;
			pj->next=pi;
		}
		pstart->next=pj;
		while (pi->next)
			pi=pi->next;
		if (pi->next!=&myend){
			pi->next=pend;
			while (pi->next!=&myend)
				pi=pi->next;
			pi->next=NULL;
		}
			
		return mystart.next;
    }
};
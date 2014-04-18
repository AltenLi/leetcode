/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

struct TreeNode {
    int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
	TreeNode* sortedList(ListNode* head, int start, int end){
		if(start>end) return NULL;
		else if (start==end)
		{
			return new TreeNode(head->val);
		}
		int mid=start+(end-start)/2;
		TreeNode* left=sortedList(head,start, mid-1);  
		for (int i=0;i<mid;i++)
			head=head->next;
		TreeNode* root= new TreeNode(head->val);
		root->left=left;
		head=head->next;
		root->right=sortedList(head, 0, end-mid-1);
		return root;
	}

    TreeNode *sortedListToBST(ListNode *head) {
		if(head==NULL) return NULL;
		    ListNode* countlen=head;
		    int len=0;
		    while(countlen!=NULL){ countlen=countlen->next;len++;}

		return sortedList(head,0,len-1);  // first find the length of linkedlist

    }
};
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct TreeLinkNode {
   int val;
   TreeLinkNode *left, *right, *next;
   TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
  };

class Solution {
public:
	void build(TreeLinkNode *root)
    {
        if(root->left!=NULL)
        {
            root->left->next=root->right;
            if(root->next!=NULL)
            {
                root->right->next=root->next->left;
            }
            else
            {
                root->right->next=NULL;
            }
            build(root->left);
            build(root->right);
        }
    }
    void connect(TreeLinkNode *root) {
        if(root==NULL)return;
        root->next=NULL;
        build(root);
        return; 
    }
};
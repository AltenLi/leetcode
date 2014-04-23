/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <set>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
	int checkLeaf(TreeNode *node,int &depth){
		if (!node){
			depth=0;
			return true;
		}
		int ldep,rdep;
		if (checkLeaf(node->left,ldep)&&checkLeaf(node->right,rdep)){
			if (abs(ldep-rdep)>1)
				return false;
		}else{
			return false;
		}
		depth=(ldep>rdep)?ldep+1:rdep+1;
		return true;
	}

    bool isBalanced(TreeNode *root) {
		if (!root)
			return true;
		int depth;
		return checkLeaf(root,depth);
    }
};
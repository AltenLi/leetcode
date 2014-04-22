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
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		set<TreeNode *> vis;
		if (root==NULL){
			return result;
		}
        vector<TreeNode *> stac;
		stac.push_back(root);
		vis.insert(root);
		if (root->right){
			stac.push_back(root->right);
		}
		if (root->left){
			stac.push_back(root->left);
		}
		while (!stac.empty()){
			TreeNode* tn=*(stac.end()-1);
			if (vis.find(tn)==vis.end()){
				vis.insert(tn);
				if (tn->right){
					stac.push_back(tn->right);
				}
				if (tn->left){
					stac.push_back(tn->left);
				}else{
					if (!tn->right){
						//leaf node
						result.push_back(tn->val);
						stac.pop_back();
					}
				}
			}else{
				result.push_back(tn->val);
				stac.pop_back();
			}
			
		}
		return result;
    }
};
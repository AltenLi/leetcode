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
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

/* MLE
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (inorder.size()==0){
			return NULL;
		}
		if (inorder.size()==1){
			return new TreeNode(inorder[0]);
		}

		int rootVal=postorder.back();
		TreeNode *root=new TreeNode(rootVal);
		
		vector<int> leftin;
		vector<int> rightin;
		vector<int> leftpost;
		vector<int> rightpost;

		bool isLeft=true;
		for (vector<int>::iterator it=inorder.begin(),it2=postorder.begin();it!=inorder.end();it++,it2++){
			if (rootVal==*it){
				isLeft=false;
				rightpost.push_back(*it2);
				continue;
			}
			if (isLeft){
				leftin.push_back(*it);
				leftpost.push_back(*it2);
			}else{
				rightin.push_back(*it);
				rightpost.push_back(*it2);
			}
		}
		rightpost.pop_back();
		root->left=buildTree(leftin,leftpost);
		root->right=buildTree(rightin,rightpost);
		return root;
    }
};
*/

/* Bug...
class Solution2 {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		if (inorder.size()==0){
			return NULL;
		}
		if (inorder.size()==1){
			return new TreeNode(inorder[0]);
		}

		vector<int>::iterator itis=(inorder.begin());
		vector<int>::iterator itie=(inorder.end()-1);
		vector<int>::iterator itps=(postorder.begin());
		vector<int>::iterator itpe=(postorder.end()-1);
		return buildMyTree(inorder,postorder,itis,itie,itps,itpe);
    }

	TreeNode *buildMyTree(vector<int> &inorder, 
						vector<int> &postorder,
						vector<int>::iterator &itis,
						vector<int>::iterator &itie,
						vector<int>::iterator &itps,
						vector<int>::iterator &itpe){
		int rootVal=*itpe;
		TreeNode *root=new TreeNode(rootVal);
		
		vector<int>::iterator it;
		vector<int>::iterator it2;
		for (it=itis,it2=itps;it!=itie;it++,it2++){
			if (rootVal==*it){
				break;
			}
		}

		if (*it==*itis){
			root->left = NULL;
		}else if (*(itis+1)==*it){
			root->left = new TreeNode(*itis);
		}else{
			root->left = buildMyTree(inorder,postorder,itis,it-1,itps,it2-1);
		}

		if (*it==*itie){
			root->right = NULL;
		}else if (*(it+1)==*itie){
			root->right = new TreeNode(*it2);
		}else{
			root->right = buildMyTree(inorder,postorder,it+1,itie,it2,itpe-1);
		}
		return root;
	}
};
*/

class Solution {
public:
    TreeNode *createTree(vector<int> &inorder, int inBeg, int inEnd, vector<int> &postorder, int postBeg, int postEnd)
    {
        if (inBeg > inEnd)
            return NULL;
            
        int root = postorder[postEnd];
        
        int index;
        
        for(int i = inBeg; i <= inEnd; i++)
            if (inorder[i] == root)
            {
                index = i;
                break;
            }
            
        int len = index - inBeg;
        TreeNode *left = createTree(inorder, inBeg, index - 1, postorder, postBeg, postBeg + len - 1);
        TreeNode *right = createTree(inorder, index + 1, inEnd, postorder, postBeg + len, postEnd - 1);
        
        TreeNode *node = new TreeNode(root);
        node->left = left;
        node->right = right;
        
        return node;
    }
    
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.size() == 0)
            return NULL;
            
        TreeNode *head = createTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
        
        return head;
    }
};
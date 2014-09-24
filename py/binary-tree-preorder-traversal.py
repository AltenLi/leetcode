# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param root, a tree node
    # @return a list of integers
    def preorderTraversal(self, root):
        if not root:
            return []
        res=[]
        self.dfs(root, res)
        return res

    def dfs(self, root, res):
        res.append(root.val)
        if root.left!=None: self.dfs(root.left,res)
        if root.right!=None: self.dfs(root.right,res)



a=Solution()
tree=TreeNode(1)
# tree.left=TreeNode(2)
tree.right=TreeNode(3)
print a.preorderTraversal({})
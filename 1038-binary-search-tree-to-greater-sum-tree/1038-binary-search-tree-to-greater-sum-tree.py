# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        sum_ = 0
        def dfs(node):
            if not node:
                return
            nonlocal sum_
            dfs(node.right)
            sum_ += node.val
            node.val = sum_
            dfs(node.left)
        dfs(root)
        return root
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root) -> int:
        return self.dfs2(root)
    def dfs2(self,root):
        if not(root):
            return 0
        left = self.dfs2(root.left)
        right = self.dfs2(root.right)
        return max(left,right)+1
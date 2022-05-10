# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        def helper(root, prvMax):
            if not root:
                return 0
            res = 1 if root.val >= prvMax else 0
            prvMax = max(root.val, prvMax)
            res += helper(root.left, prvMax) + helper(root.right, prvMax)
            return res
        
        return helper(root, root.val)
            
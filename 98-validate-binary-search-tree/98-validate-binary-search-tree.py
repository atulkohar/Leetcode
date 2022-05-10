# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        def helper(root,min,max):
            if root == None:
                return True
            if root.val <= min or root.val >= max:
                return False
            left = helper(root.left,min,root.val)
            right = helper(root.right,root.val,max)
            return left and right
        return helper(root,-inf,inf)
        
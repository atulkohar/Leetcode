# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = [root.val]
        
        def dfs(root):
            if not root:
                return 0
            left = dfs(root.left)
            right = dfs(root.right)
            leftMax = max(left, 0)
            rightMax = max(right, 0)
            
            ans[0] = max(ans[0], root.val + leftMax + rightMax)
            
            return root.val + max(leftMax, rightMax)
        
        dfs(root)
        return ans[0]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        ret = 0
        
        def dfs(gp, p, r):
            nonlocal ret
            
            if not r:
                return 
            if gp:
                ret += r.val
            
            if not r.val % 2:
                dfs(p, True, r.left)
                dfs(p, True, r.right)
            else:
                dfs(p, False, r.left)
                dfs(p, False, r.right)
        
        dfs(False, False, root)
        
        return ret
        
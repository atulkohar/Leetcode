# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        res = [False]
        res_subtree = [True]
        def dfs(root, subRoot):
            if not root or res[0]: return None
            if root.val == subRoot.val:
                dfs_2(root, subRoot)
                res[0] = res[0] or res_subtree[0]
                if res[0]: return None
                else: res_subtree[0] = True
            left  = dfs(root.left, subRoot)
            right = dfs(root.right, subRoot)
            return None
        
        def dfs_2(root1, root2):
            if not root1 and not root2: return None
            if not root1 or not root2:
                res_subtree[0] = False
                return None
            left  = dfs_2(root1.left, root2.left)
            right = dfs_2(root1.right, root2.right)
            res_subtree[0] = res_subtree[0] and (root1.val == root2.val)
            return None
        
        dfs(root, subRoot)
        return res[0]
            
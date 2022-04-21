# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        lst = []
        def helper(root,lst):
            if not root:
                return
            helper(root.left,lst)
            lst.append(root.val)
            helper(root.right,lst)
        helper(root,lst)
        lst.sort()
        def makeTree(lst):
            if not lst:
                return None
            i = len(lst)//2
            root = TreeNode(lst[i])
            root.left = makeTree(lst[:i])
            root.right = makeTree(lst[i+1:])
            return root
        return makeTree(lst)
    
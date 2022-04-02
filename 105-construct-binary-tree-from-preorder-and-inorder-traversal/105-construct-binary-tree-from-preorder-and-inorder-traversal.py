# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.i = -1
    def buildTree(self, preorder: List[int], inord: List[int]) -> Optional[TreeNode]:
        if not inord: return None
        self.i += 1
        val = preorder[self.i]
        ind = inord.index(val)
        root = TreeNode(val)
        root.left = self.buildTree(preorder,inord[:ind])
        root.right = self.buildTree(preorder,inord[ind+1:])
        return root
        
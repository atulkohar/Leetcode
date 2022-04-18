# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, node, temp=0):
        res = 0
        if node.left == node.right == None: return (temp<<1) + node.val
        if node.left:  res += self.sumRootToLeaf(node.left, (temp<<1) + node.val)
        if node.right: res += self.sumRootToLeaf(node.right,(temp<<1) + node.val) 
        return res
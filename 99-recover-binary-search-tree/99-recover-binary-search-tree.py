# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution():
    def recoverTree(self, root):

        def inorderBST(root):
            if not root:    return
            
            inorderBST(root.left)

            if self.prev and self.prev.val > root.val:
                if not self.first:  self.first = self.prev
                self.second = root
            self.prev = root

            inorderBST(root.right)
        
        
        self.first = self.second = self.prev = None
        inorderBST(root)
        self.first.val, self.second.val = self.second.val, self.first.val
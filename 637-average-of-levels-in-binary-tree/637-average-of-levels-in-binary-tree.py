# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        if not root:
            return root
        q = [root]
        level = []
        res = [root.val]
        x = 0
        while q and root:
            for node in q:
                if node.left:
                    level.append(node.left)
                if node.right:
                    level.append(node.right)
            temp = []
            for i in level:
                temp.append(i.val)
            if temp:
                res.append(sum(temp)/len(temp))
            q = level
            level = []
        return res
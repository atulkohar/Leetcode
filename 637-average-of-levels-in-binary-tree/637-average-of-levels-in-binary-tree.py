# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        d=defaultdict(lambda: [0,0])
        def f(r,l=0):
            if not r:return 
            d[l]=[d[l][0]+r.val,d[l][1]+1]
            f(r.left,l+1),f(r.right,l+1)
        f(root)
        return [d[i][0]/d[i][1] for i in range(max(d.keys())+1)]
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root==None:
            return None
        ans=[]
        queue=[]
        queue.append([root,0])
        ans.append([root.val])
        currLevel=0
        currList=[]
        while(queue!=[]):
            temp,level=queue.pop(0)
            if currLevel!=level:
                ans.append(currList)
                currList=[]
                currLevel=level
            if temp.left:
                queue.append([temp.left,level+1])
                currList.append(temp.left.val)
            if temp.right:
                queue.append([temp.right,level+1])
                currList.append(temp.right.val)
        return ans
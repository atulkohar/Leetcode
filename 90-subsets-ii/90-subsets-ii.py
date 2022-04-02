class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort() #sorting nums to get all subset in dictionary order
        res = []
        subset= []
        def dfs(i):
            if i >= len(nums):
                res.append(subset.copy())
                return
            subset.append(nums[i])
            #decission taking nums[i]
            dfs(i+1)
            #decission not taking nums[i]
            subset.pop()
            dfs(i+1)
        dfs(0)
        ans = []
		#function to remove repeating sub set from ans,
        for i in res:
            if i not in ans:
                ans.append(i)
        return ans
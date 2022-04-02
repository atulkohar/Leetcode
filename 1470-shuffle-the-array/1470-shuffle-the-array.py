class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        ans = []
        k = 0
        for i in range(0,n):
            ans.append(nums[i])
            ans.append(nums[n+i])
        if(len(nums) & 1):
            ans.append(nums[n*n])
        return ans
        
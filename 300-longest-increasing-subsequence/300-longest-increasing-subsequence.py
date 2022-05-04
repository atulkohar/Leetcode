class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        lst = [1] * len(nums)
        
        for i in range(len(nums)-1, -1, -1):
            for j in range(i+1, len(nums)):
                if nums[i] < nums[j]:
                    lst[i] = max(lst[i], 1+lst[j])
        return max(lst)
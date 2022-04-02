class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        lst = []
        for x in nums:
            lst.append(nums[x])
        return lst
        
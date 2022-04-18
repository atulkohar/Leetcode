class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        prev = 0
        count = 1
        for i in nums:
            if(i == prev):
                count += 1
            else:
                count -= 1
            if(count == 0):
                count = 1
                prev = i
        return prev
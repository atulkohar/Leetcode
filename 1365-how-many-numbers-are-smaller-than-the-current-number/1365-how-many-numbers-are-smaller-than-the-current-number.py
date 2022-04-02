class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        
        nums1 = nums.copy()
        nums1.sort()
        hash = {}
        n = len(nums1)
        j = 0
        for i in range(n-1,-1,-1):
            hash[nums1[i]] = i
            
        
        arr = []
        for i in nums:
            arr.append(hash[i])
        return arr
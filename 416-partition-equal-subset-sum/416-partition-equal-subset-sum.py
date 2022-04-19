class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        def rec(idx, target):
            if (idx, target) in memo:
                return False
            if target == 0:
                return True
            elif target < 0 or idx == N:
                return False
            
            flag = rec(idx + 1, target - nums[idx]) or rec(idx + 1, target)
            if flag:
                return True
            memo.add((idx, target))
            return False
        
        total_sum = sum(nums)
        #edge case
        if total_sum % 2 == 1:
            return False
        
        memo = set()
        N = len(nums)
        return rec(0, total_sum // 2)
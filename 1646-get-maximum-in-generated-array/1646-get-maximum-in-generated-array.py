class Solution:
    def getMaximumGenerated(self, n: int) -> int:
        # simulation 
        maxi = 0 if n == 0 else 1
        @functools.lru_cache(None)
        def helper(num):
            if num in {0, 1}:   return num
            if num % 2 == 0:
                val = helper(num // 2)
            else:
                val = helper(num // 2) + helper((num // 2) + 1)
            return val
        for i in range(n, 0, -1):
            maxi = max(maxi, helper(i))
        return maxi
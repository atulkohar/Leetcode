class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        map = { _:0 for _ in nums }
        ans = 0
        for i in nums:
            if(map[i] > 0):
                ans += map[i]
            map[i]+=1;
        return ans
                
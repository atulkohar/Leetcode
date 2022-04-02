class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        ans = 0
        for x in accounts:
            temp = 0
            for i in x:
                temp += i
                ans = max(temp,ans)
        return ans
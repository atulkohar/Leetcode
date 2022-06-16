# class Solution:
#     def climbStairs(self, n: int) -> int:
#         one, two = 1, 1
#         for i in range(n-1):
#             temp = one
#             one = one+two
#             two = temp
#         return one

class Solution:
    def climbStairs(self, n: int) -> int:
        dp = {}
        def help(i, n):
            if i == n:
                return 1
            if i > n:
                return 0
            if (i, n) in dp:
                return dp[(i,n)]
            dp[(i,n)] = help(i+1, n) + help(i+2, n)
            return dp[(i,n)]
        return help(0, n)
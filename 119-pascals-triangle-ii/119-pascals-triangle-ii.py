class Solution:
    def getRow(self, n: int) -> List[int]:
        if n == 0:
            return [1]
        if n == 1:
            return [1,1]
        ans = [1,1]
        n -= 1
        while(n > 0):
            lst = []
            lst.append(ans[0])
            for i in range(1,len(ans)):
                lst.append(ans[i-1] + ans[i])
            lst.append(ans[-1])
            ans = lst
            n-=1
        return ans
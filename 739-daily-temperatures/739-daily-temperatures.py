class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        #NGR
        stack = []
        res = []
        for i in range(len(temperatures)-1, -1, -1):
            if  len(stack) == 0:
                res.append(0)
            elif len(stack)>0 and stack[-1][0] > temperatures[i]:
                res.append(stack[-1][1]-i)
            else: #len(stack)>0 and temperatures[i]<stack[-1][0]:
                while len(stack) >0 and stack[-1][0] <= temperatures[i]:
                    stack.pop()
                if len(stack) == 0:
                    res.append(0)
                else:# stack and temperatures[i] > stack[-1][0]:
                    res.append(stack[-1][1]-i)
            stack.append([temperatures[i], i])
        l , r = 0, len(res)-1
        while l<r:
            res[l], res[r] = res[r], res[l]
            l+=1
            r-=1
        return res
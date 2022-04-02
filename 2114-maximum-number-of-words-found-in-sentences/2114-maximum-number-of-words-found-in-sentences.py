class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        ans = 0
        for i in sentences:
            str = i
            temp = 0
            ans = max(ans,str.count(" ")+1)
        return ans
        
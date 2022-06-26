class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        lst = []
        sum = 0
        for i in range(k):
            sum += cardPoints[i]
        lst.append(sum)
        
        i = k-1
        j = len(cardPoints) - 1
        
        while i >= 0:
            sum += cardPoints[j] - cardPoints[i]
            i -= 1
            j -= 1
            lst.append(sum)
            
        print(lst)
        
        return max(lst)
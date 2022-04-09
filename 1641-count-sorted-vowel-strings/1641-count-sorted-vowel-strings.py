class Solution:
    def countVowelStrings(self, n: int) -> int:
        lst = [1,1,1,1,1]
        count = 5
        for i in range(2,n+1):
            temp = 0
            for j in range(5):
                temp = count
                count -= lst[j]
                lst[j] = temp
            count = sum(lst)
            print(count)
        return count
            
        
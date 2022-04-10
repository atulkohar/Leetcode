class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        ind = -1
        for i in range(len(word)):
            if word[i] == ch:
                ind = i
                break
        if ind == -1:
            return word
        string = word[:ind:-1] + word[:ind+1]                
        return string[::-1]
        
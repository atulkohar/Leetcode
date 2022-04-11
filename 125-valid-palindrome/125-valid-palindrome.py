class Solution:
    def isPalindrome(self, s: str) -> bool:
        string = ""
        for i in range(len(s)):
            if (s[i] >= 'a' and s[i] <= 'z')  or (s[i] >= 'A' and s[i] <= 'Z'):
                string += s[i].lower()
            elif(s[i] >= '0' and s[i] <= '9'):
                string += s[i]
        i = 0
        j = len(string) - 1
        print(string)
        while i < j:
            if string[i] != string[j]:
                return False
            i+=1
            j-=1
        return True
        
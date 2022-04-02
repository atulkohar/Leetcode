class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        i = 0
        for x in operations:
            str = x
            flag = 0
            if(str.count('-') > 0):
                i -= 1
            else:
                i += 1
        return i
        
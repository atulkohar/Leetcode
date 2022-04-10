class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        res = []
        
        for row in image:
            row2 = []
            for i in row[::-1]:
                if i == 1:
                    row2.append(0)
                else:
                    row2.append(1)
            res.append(row2)
        return res
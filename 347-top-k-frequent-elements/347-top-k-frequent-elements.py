class Solution(object):
    def topKFrequent(self, nums, k):
        dic = {}
        for i in nums:
            dic[i] = dic.get(i, 0) + 1
        
        arr = sorted(dic, key = dic.get, reverse = True)
        return arr[:k]
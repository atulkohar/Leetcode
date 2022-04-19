class Solution:
    def canPartition(self, nums):
        def issubsetpossible(subsetsum,index):
            if index >= len(nums) or subsetsum < 0:
                return False

            if subsetsum == 0:
                return True

            if cache[index][subsetsum] != None:
                #print(cache)
                return cache[index][subsetsum]        


            res =  issubsetpossible(subsetsum-nums[index],index+1) or \
                                issubsetpossible(subsetsum, index+1)

            cache[index][subsetsum] = res

            return res


        if sum(nums)%2 != 0:
            return False        

        #if sum is even
        subsetsum = sum(nums)//2    

        #memoization
        cache = [[None]*(subsetsum+1) for _ in range(len(nums))]

        return issubsetpossible(subsetsum,0)
class Solution(object):
    def twoCitySchedCost(self, costs):
        costs.sort(key = lambda x: x[0]-x[1])
        total = 0
        for i in range(0, len(costs)):
            if i < len(costs)/2 :
                total += costs[i][0]
            else:
                total += costs[i][1]
        return total
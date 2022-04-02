class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # it's a straight-forward approach, and I'm too lazy to think it through
        buy = prices[0]
        sell = prices[0]
        # let's just write down all the profits, why not. 0 for the egde case.
        profits = [0]
        
        # now let's iterate over the array once
        for p in prices[1:]:
            # if we have a better price to sell, well, let's sell
            if p > sell:
                sell = p
                profits.append(sell - buy)
            # if we have a lower price to buy, let's use it and update the selling price
            # we already wrote down the best deal before this point
            if p < buy:
                buy = p
                sell = p
        return max(profits)
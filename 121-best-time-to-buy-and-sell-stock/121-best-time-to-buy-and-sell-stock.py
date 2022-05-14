class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # it's a straight-forward approach, and I'm too lazy to think it through
        buy = inf
        sell = 0
        for i in prices:
            buy = min(buy, i);
            sell = max(sell, i-buy)
        return sell
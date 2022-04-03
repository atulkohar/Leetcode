class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        firstBuy = float('-inf')
        firstSell = 0
        secondBuy = float('-inf')
        secondSell = 0
        for i in prices:
            firstBuy = max(firstBuy,-i);
            firstSell = max(firstSell,firstBuy + i)
            secondBuy = max(secondBuy, firstSell - i)
            secondSell = max(secondSell, secondBuy + i)
        return secondSell
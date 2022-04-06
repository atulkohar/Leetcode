class Solution {
public:
    int dp[102][1002][2];
    
    int solve(vector<int>& prices, int k, int idx, int buy){
        if(idx >= prices.size()) return 0;
        if(dp[k][idx][buy] != -1) return dp[k][idx][buy];
        
        int op1 = 0, op2 = 0;
        op1 = solve(prices, k, idx + 1, buy);
        
        if(buy){
           op2 = prices[idx] + solve(prices, k, idx + 1, 0);    
        }
        
        if(!buy && k > 0){
            op2 = solve(prices, k - 1, idx + 1, 1) - prices[idx];
        }
        
        return dp[k][idx][buy] = max(op1, op2);
    }
    
    int maxProfit(int k, vector<int>& prices) {
         memset(dp, -1, sizeof(dp));
         return solve(prices, k, 0, 0);
    }
};
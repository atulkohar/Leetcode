class Solution
{
    public:
        vector<int> dp ; 
        int minCost(vector<int> &days,vector<int> &costs,int index)
        {
            if (index < 0) return 0;
            if (dp[index] == -1)
            {
                int oneDay = INT_MAX, sevenDay = INT_MAX, thirtyDay = INT_MAX;
                
                oneDay = minCost(days,costs,index - 1) + costs[0];
                
                int firstDay = days[index] - 7 + 1;
                int tempIndex = lower_bound(days.begin() , days.end(),firstDay) - days.begin() ; 
                tempIndex-- ; 
                sevenDay = minCost(days,costs,tempIndex) + costs[1];
                
                firstDay = days[index] - 30 + 1;
                tempIndex = index;
                tempIndex = lower_bound(days.begin() , days.end(),firstDay) - days.begin() ; 
                tempIndex-- ;
                thirtyDay = minCost(days,costs,tempIndex) + costs[2];
                
                dp[index] = min({oneDay, sevenDay, thirtyDay});
            }
            return dp[index] ; 
        }
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        int n = days.size() ;
        dp.assign(n,-1) ; 
        return minCost(days,costs,n-1) ; 
    }
};
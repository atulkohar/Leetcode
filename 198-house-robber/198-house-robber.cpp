class Solution {
public:
    int dp[1000];
    int helper(vector<int> &arr, int n)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return arr[0];
        if(dp[n] != -1)
            return dp[n];
        int ans1 = arr[n] + helper(arr,n-2);
        int ans2 = helper(arr,n-1);
        return dp[n] = max(ans1,ans2);
    }
    
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        // if(nums.size() == 1)
        //     return nums[0];
        // if(nums.size() == 2)
        //     return max(nums[0],nums[1]);
        return helper(nums,nums.size()-1);
    }
};
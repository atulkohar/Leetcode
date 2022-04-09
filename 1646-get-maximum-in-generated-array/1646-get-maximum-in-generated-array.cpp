class Solution {
public:
    int getMaximumGenerated(int n) 
    {
		// if n equals to 0 then we will have a single element array with value as 0 so simply return 0 instead of array formation
        if(n == 0)  return n;
        
        int dp[n+1];
        memset(dp, 0, sizeof(dp));
        
		// initialise variable ans
        int ans = 1;
        
        dp[0] = 0;
        dp[1] = 1;
        
		// looping is as per the constraints in the problem by seeing the range and reducing it mathematically #easy-peasy \U0001f971
        for(int i=1, j=1; i<=n/2 && j<=(n-1)/2; i++, j++)
        {
            dp[2*i] = dp[i];
            dp[2*j+1] = dp[j] + dp[j+1]; 
			// keep track of maximum element so far obtained
            ans = max(ans, max(dp[2*i], dp[2*j+1]));
        }
        
        return ans;
    }
};
class Solution {
public:
    int dp[1005][3];
	int solve(int n, int eggs){
    
        if(dp[n][eggs]!=-1)
            return dp[n][eggs];
        if(n<=1 || eggs==1)
            return n;

        int mini = INT_MAX;
        for(int i=1;i<n;i++)
            mini = min(mini, max(solve(i-1, eggs-1), solve(n-i, eggs))+1);

        return dp[n][eggs] = mini;
    }

    int twoEggDrop(int n) {

        memset(dp, -1, sizeof(dp));
        return solve(n, 2);
    }
};
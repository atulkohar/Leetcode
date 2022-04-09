class Solution
{
public:
    int dp[10001];
    int helper(int n)
    {
        if (n == 1)
            return 0;
        if (dp[n] != -1)
        {
            return dp[n];
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if (n % i == 0)
                {
                    if (helper(n - i) == 0)
                        return dp[n] = 1;
                }
            }
            return dp[n] = 0;
        }
    }
    bool divisorGame(int n)
    {
        memset(dp, -1, sizeof dp);
        return helper(n);
    }
};
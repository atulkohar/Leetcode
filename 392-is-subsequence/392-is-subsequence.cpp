class Solution {
public:
    
    int dp[102][10002];
    int helper(string s, string t, int n, int m)
    {
        if(n==0 or m == 0)
            return 0;
        if(dp[n-1][m-1] != -1)
            return dp[n-1][m-1];
        if(s[n-1] == t[m-1])
            return dp[n-1][m-1] = 1 + helper(s,t,n-1,m-1);
        else
            return dp[n-1][m-1] = max(helper(s,t,n-1,m),helper(s,t,n,m-1));
    }
    
    bool isSubsequence(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return s.size() == helper(s,t,s.size(),t.size());
    }
};
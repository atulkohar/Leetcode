class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n));
        for(int i=0; i<triangle[n-1].size(); i++)
            dp[n-1][i] = triangle[n-1][i];
        int i=n-2;
        while(i >= 0)
        {
            int size = triangle[i].size();
            for(int j=0; j<size; j++)
            {
                dp[i][j] += triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
            i--;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[0][0];
    }
};
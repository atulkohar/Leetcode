class Solution {
public:

int numSquares(int n) {
    int dp[10001]={0};
    for(int i=1;i<=n;i++){
        int cnt=INT_MAX;
        for(int j=1;j*j<=i;j++){
            cnt=min(cnt,1+dp[i-j*j]);
        }
        dp[i]=cnt;
    }
    return dp[n];
}
};
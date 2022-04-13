class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n));
        int i=0; 
        int k=1;
        while(k <= n*n){
            int j = i;
            while(j<n-i){
                ans[i][j] = k;
                j++;
                k++;
            }
            j = i+1;
            while(j<n-i){
                ans[j][n-i-1] = k;
                k++;
                j++;
            }
            j = n-i-2;
            while(j>i){
                ans[n-i-1][j] = k;
                k++;
                j--;
            }
            j = n-i-1;
            while(j>i){
                ans[j][i] = k;
                j--;
                k++;
            }
            i++;
        }
        return ans;
    }
};
class Solution
{
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>frnt(n,0),back(n,0);
        
        for(int i=1;i<n;i++){
            
            if(ratings[i] > ratings[i-1])
                frnt[i] = 1 + frnt[i-1];
            
            if(ratings[n-1-i] > ratings[n-i])
                back[n-1-i] = 1 + back[n-i];
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = ans + 1 + max(frnt[i] , back[i]);
        }
        return ans;
    }
};
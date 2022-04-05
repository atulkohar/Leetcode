class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxSoFar= nums[0];
        int minSoFar= nums[0];
        int ans= maxSoFar;
        
        for(int i=1; i<nums.size(); i++) {
            int curr= nums[i];
            
            int temp_max= max(curr, max(maxSoFar*curr, minSoFar*curr));
            // creating temp max as we want to use old maxSoFar and minSoFar and not updated ones in further calculating minSoFar & maxSoFar
            
            minSoFar= min(curr, min(maxSoFar*curr, minSoFar*curr));
            maxSoFar= temp_max;
            
            ans= max(maxSoFar, ans);
        }
        
        return ans;
    }
};
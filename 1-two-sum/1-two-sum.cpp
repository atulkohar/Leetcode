class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans, nums2;
        nums2 = nums;
        sort(nums.begin(), nums.end());        
        int sum, p1 = 0, p2 = nums.size() - 1;
        sum = nums[p1] + nums[p2];
        while(p1 < p2){
            if(sum == target){                        
                break;
            }
            else if(sum > target){
                sum -= nums[p2];                
                sum += nums[--p2];
            }
            else{            
                sum -= nums[p1];
                sum += nums[++p1];
            }
        }
        for(int i = 0; i < nums2.size(); i++){
            if(nums2[i] == nums[p1])
                ans.push_back(i);
            else if(nums2[i] == nums[p2])
                ans.push_back(i);
        }
        return ans;
    }
};
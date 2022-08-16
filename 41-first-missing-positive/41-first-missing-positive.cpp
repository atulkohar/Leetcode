class Solution {
public:
    
    // Cyclic sort 
    // Arr :      [1,2,3,4,5,6] 
    // indices :  [0,1,2,3,4,5]   arr[i] == i+1               
    int firstMissingPositive(vector<int>&nums) 
    {
        int i = 0;
        int n = nums.size();
        while(i < n)
        {
            if(nums[i] > 0 and nums[i] <= n && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i]-1]);
            }
            else
                i++;
        }
        
        for(i=0;i<n;i++){
            if(nums[i] != i + 1){
                return (i + 1); // missing positive number 
            }
        }
        return n + 1; // [1,2,3] , ans  = 4 (missing positive integers)
    }
};
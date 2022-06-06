class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int target =0 ;
        for(int & i: nums) target= (target+i)%p;
        if(!target) return 0 ;
        
        unordered_map<int,int>  umap ;
        int curr_sum = 0 ,len = nums.size() ;
        
        umap[0] =  -1 ; 
        
       for(int i=0 ;i<nums.size() ;i++)
        {
            curr_sum= (curr_sum+nums[i])%p;
            int prev_sum =(p+curr_sum-target)%p ;
            if(umap.find(prev_sum)!= umap.end()) len = min(len , i-umap[prev_sum]) ;
            umap[curr_sum] = i ;
        }
        
        return len >= nums.size()?-1:len ;
    }
};
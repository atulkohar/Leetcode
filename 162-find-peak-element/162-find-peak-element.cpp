class Solution {
public:
    
    bool isPeakElement(vector<int> &nums, int &m, int &n){
        
        int count = 0;
        if( m == 0 || nums[m] > nums[m-1] ) count += 1;
        if( m == n-1 || nums[m] > nums[m+1] ) count += 1;
        
        return count==2;
    }
    
    int findPeakElement(vector<int>& nums) {
        
        int n = nums.size(), l = 0, u = n-1, m = (l+u)/2;
        
        while( l<=u ){
            
            if( isPeakElement(nums, m, n) ) return m;
            else if( m == n-1 || (m>0 && nums[m-1] > nums[m+1]) ) u = m-1;
            else l = m+1;
            
            m = (l+u)/2;
        }
        return -1;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        int i = 0;
        int j = 0;
        while (i < nums.size()) {
            j = i;
            while (j < nums.size() && nums[j] == nums[i]) {
                j++;
            }
            for (int k = i; k < i + min(2, j - i); k++) {
                nums[idx++] = nums[k];
            }
            
            i = j;
            
        }
        
        return idx;
    }
};
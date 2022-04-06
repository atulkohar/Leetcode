class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        
		//reverse the array from starting to end
        reverse(nums.begin(), nums.end());
		
		//reverse from starting till kth element
        reverse(nums.begin(), nums.begin()+k);
		
		//reverse from kth till last element
        reverse(nums.begin()+k, nums.end());
    }
};
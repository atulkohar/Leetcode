/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int> arr, int i, int j)
    {
        if(i > j)
            return NULL;
        int mid = (i+j)/2;
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = helper(arr,i,mid-1);
        root->right = helper(arr,mid+1,j);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        return helper(nums,0,nums.size()-1);
    }
};
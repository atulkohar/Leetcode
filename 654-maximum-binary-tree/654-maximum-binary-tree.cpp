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
    TreeNode* construct(vector<int>& nums,int s,int n){
        if(s>n)return NULL;
         int m=-1;
        int j=-1;
        for(int i=s;i<=n;i++){
            if(nums[i]>=m){
                m=nums[i];
                 j=i;
            }
        }
            TreeNode* root=new TreeNode(m);
            root->left=construct(nums,s,j-1);
             root->right=construct(nums,j+1,n);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      return construct(nums,0,nums.size()-1);
        
    }
};
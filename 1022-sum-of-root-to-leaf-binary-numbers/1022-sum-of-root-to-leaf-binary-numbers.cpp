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
    int ans{0}, cur{0};
public:
    int sumRootToLeaf(TreeNode* root) {
        recurse(root);
        return ans;
    }
    void recurse(TreeNode* root){
        //shift left by 1. increasing depth
        cur = (cur << 1) | root->val;
        //test if leaf
        if(not root->left and not root->right)
            ans += cur;
        else{
            if(root->left)
                recurse(root->left);
            if(root->right)
                recurse(root->right);
        }
        //going upwards now
        cur >>= 1;
    } 
};
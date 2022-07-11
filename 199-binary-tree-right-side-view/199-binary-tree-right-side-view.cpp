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
    int height;
    vector<int> v;
    void helper(TreeNode *root, int curr)
    {
        if(root == NULL)
            return;
        if(height < curr)
            v.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            height = max(curr, height);
            return;
        }
        if (root->right != NULL)
            helper(root->right, curr + 1);
        if (root->left != NULL)
            helper(root->left, curr + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        height = INT_MIN;
        helper(root,1);
        return v;
    }
};
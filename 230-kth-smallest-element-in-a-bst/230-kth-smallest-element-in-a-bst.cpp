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
class Solution
{
public:
    void inorderSolve(TreeNode *root, int k, vector<int> &result)
    {
        if (root == NULL)
            return;
        inorderSolve(root->left, k, result);
        result[0] = result[0] + 1;
        if (result[0] == k)
        {
            result[1] = root->val;
            return;
        }
        inorderSolve(root->right, k, result);
        return;
    }
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> result = {0, -1};
        inorderSolve(root, k, result);
        return result[1];
    }
};
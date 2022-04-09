class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n)
    {
        if(n==0)
            return {};
         vector<TreeNode*>ans;
        if(n==1)
        {
             TreeNode* p=new TreeNode();
             ans.push_back(p);
            return ans;
        }
        
        for(int i=1;i<=n-1;i+=2)
        {
            vector<TreeNode*>left=allPossibleFBT(i);
            vector<TreeNode*>right=allPossibleFBT(n-1-i);
            
            for(auto i:left)
            {
                for(auto j:right)
                {
                    TreeNode* p=new TreeNode();
                    p->left=i;
                    p->right=j;
                    ans.push_back(p);
                }
            }
                
        }
        return ans;
        
    }
};
class Solution
{
public:
    vector<vector<int>> res;
    void solve(vector<int> &nums, int pos)
    {
        if (pos == nums.size() - 1)
        {
            res.push_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++)
        {
            swap(nums[pos], nums[i]);
            solve(nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int> &nums)
    {
        solve(nums, 0);
        return res;
    }
};
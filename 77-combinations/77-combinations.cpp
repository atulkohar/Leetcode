class Solution
{
public:
    void group(vector<vector<int>> &sol, vector<int> &pair, int n, int k)
    {
        if (k == 1)
        {
            for (int i = 1; i <= n; i++)
            {
                pair.push_back(i);
                sol.push_back(pair);
                pair.pop_back();
            }
            return;
        }

        for (int i = n; i >= k; i--)
        {
            pair.push_back(i);
            group(sol, pair, i - 1, k - 1);
            pair.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {

        vector<int> pair;
        vector<vector<int>> sol;
        group(sol, pair, n, k);
        return sol;
    }
};
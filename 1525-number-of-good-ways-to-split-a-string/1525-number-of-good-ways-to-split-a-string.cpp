class Solution
{
public:
    int numSplits(string s)
    {
        int n = s.size();
        vector<int> prefix(n + 1), suffix(n + 1);
        prefix[0] = 0, suffix[n] = 0;
        unordered_set<int> m;
        for (int i = 1; i <= n; i++)
        {
            m.insert(s[i - 1]);
            prefix[i] = m.size();
        }
        m.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            m.insert(s[i]);
            suffix[i] = m.size();
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (prefix[i] == suffix[i])
                ans++;
        }
        return ans;
    }
};
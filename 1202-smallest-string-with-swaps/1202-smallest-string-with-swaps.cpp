class Solution {
    
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        vector<int> p(n); // parent array for DSU
        iota(p.begin(), p.end(), 0);
        function<int(int)> f = [&](int u) { return p[u] == u ? u : p[u] = f(p[u]); }; // find function for DSU
        for (auto i : pairs) {
            int u = i[0], v = i[1];
            u = f(u), v = f(v);
            p[u] = v; // connect the two nodes of current edge
        }
        vector<string> a(n); // list of characters of each representitive
        for (int i = 0; i < n; ++i) a[f(i)] += s[i];
        for (auto &i : a) sort(i.rbegin(), i.rend()); // sort descending for each representitive
        for (int i = 0; i < n; ++i) {
            s[i] = a[f(i)].back();
            a[f(i)].pop_back();
        }
        return s;
    }
};
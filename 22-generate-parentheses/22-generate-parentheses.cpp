class Solution {
private:
    void DFS(string cur, vector<string>& ans, int open, int close, int& n) {
        if(open > n || close > n || close > open) return;
        if(close == n) {
            ans.push_back(cur);
            return;
        }
        DFS(cur + "(", ans, open + 1, close, n);
        DFS(cur + ")", ans, open, close + 1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur = "";
        DFS(cur + "(", ans, 1, 0, n);
        return ans;
    }
};
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        int k;
        ans.push_back(first);
        for(auto it: encoded){
            k=it^first;
            ans.push_back(k);
            first=k;
        }
        return ans;
    }
};
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> m;
        int ans = 0;
        for(int i = 0; i < time.size(); ++i){
            int mod = time[i]%60;
            if(mod == 0){
                if(m.find(0) != m.end())
                    ans += m[0];
            }
            else if(m.find(60-mod) != m.end())
                ans += m[60-mod];
            ++m[mod];
        }
        return ans;
    }
};
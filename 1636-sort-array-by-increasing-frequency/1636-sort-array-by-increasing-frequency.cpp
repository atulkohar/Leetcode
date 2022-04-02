class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for (auto i : nums)
            freq[i]++;
    
        map<int, vector<int>> freqToNums;
        vector<int> res;
        
        for (auto i : nums)
            freqToNums[freq[i]].push_back(i);
        
        
        for (auto i : freqToNums)
        {
            vector<int> vec = i.second;
            sort(vec.begin(), vec.end(),greater<int>());
            for (auto j : vec)
                res.push_back(j);
        }
        
        return res;
    }
};
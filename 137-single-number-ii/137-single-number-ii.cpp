class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>m;
        int k;
        for(auto x:nums)
        {
            m[x]++;
        }
        for(auto it:m)
        {
            if(it.second==1)
            {
                k=it.first;
                break;
            }
        }
        return k;
    }
};
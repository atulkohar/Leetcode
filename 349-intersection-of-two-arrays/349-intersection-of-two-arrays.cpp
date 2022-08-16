class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        unordered_set<int> mp;
        for(int i=0;i<nums1.size();i++)
            {
            mp.insert(nums1[i]);
            }
        for(int i=0;i<nums2.size();i++)
        {
            int key=nums2[i];
            if(mp.find(key)!=mp.end())
            {
                vec.push_back(key);
                mp.erase(key);
            }
        }
        return vec;
    }
};
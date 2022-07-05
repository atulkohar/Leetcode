class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]++;
        int ans=1,res=0;
        int prev=INT_MIN;
        for(auto x:mp)
        {
            if(x.first!=1+prev)
                ans=1;
            else if(x.first==prev+1)
                ans++;
            prev=x.first;
            res=max(res,ans);
        }
        return res;
    }
};
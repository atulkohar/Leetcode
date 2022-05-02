class Solution {
public:
    bool isGood_f(vector<int>&nums,int mid,int x)
    {
        if(nums[mid]>=x) return true;
        else return false;
    }
    bool isGood_r(vector<int>&nums,int mid,int x)
    {
        if(nums[mid]<=x) return true;
        else return false;
    }
    vector<int> targetIndices(vector<int>& nums, int x) {
        sort(nums.begin(),nums.end());
        if(x<nums[0]||x>nums[nums.size()-1]) return {};
        if(nums.size()==1)
        {
            if(nums[0]==x) return {0};
            else return {};
        }
        int l=-1,r=nums.size();
        while(l+1<r)
        {
            int mid=(l+(r-l)/2);
            if(isGood_f(nums,mid,x)) r=mid;
            else l=mid;
        }
        int lf=-1,rg=nums.size();
        while(lf+1<rg) 
        {
            int mid=(lf+(rg-lf)/2);
            if(isGood_r(nums,mid,x)) lf=mid;
            else rg=mid;
        }
        if(nums[r]!=x&&nums[lf]!=x) return {};
        vector<int>v;
        for(int i=r;i<=lf;i++)
        {
            v.push_back(i);
        }
        return v;
    }
};
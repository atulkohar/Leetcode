class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) 
            if(nums[i]<=0) 
                nums[i]=n+1;
        for(int i=0;i<n;i++){
            int p=abs(nums[i]);
            if(p<=n&&nums[p-1]>0) 
                nums[p-1]*=-1; 
        }
        for(int i=0; i<n; i++)
            cout<<nums[i]<<" ";
        int i=0;
        while(i<n&&nums[i]<0) 
            i++;
        return i+1;
    }
};
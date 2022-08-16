class Solution {
public:
    long long int max(long long int a, long long int b){
        return a>b? a:b;
    }
    int firstMissingPositive(vector<int>& nums) {
        long long int maxi=0;
        
        if(nums.size()==1 && nums[0]!=1)
            return 1;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>600000)
                nums[i]=-1;
            
            maxi=max(maxi, nums[i]);
        }
        
        long long int h[maxi+1];
        for(int i=0; i<maxi+1; i++)
            h[i]=0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i] >0 )
                h[nums[i]]++;
        }
        
        int count;
        for(int i=1; i<maxi+1; i++){
            if(h[i]==0){
                count=i;
                break;
            } 
        }
        return count;
    }
};
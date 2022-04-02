class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int i=1; i<arr.size(); i++)
            arr[i] = arr[i] + arr[i-1];
        for(int i=0; i<arr.size(); i++)
        {
            int sum = arr[i]%k;
            if(sum == 0 and i)
                return true;
            if(m.find(sum) != m.end())
            {
                if(i - m[sum] > 1)
                    return true;
            }
            else 
                m[sum] = i;
        }
        return false;
    }
    
};
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b){return a[1] > b[1];});
        for(int i=0; i<n; i++){
            int val1 = boxTypes[i][0];
            int val2 = boxTypes[i][1];
            if(truckSize == 0)
                break;
            if(val1 <= truckSize){
                ans += val1*val2;
                truckSize -= val1;
            }
            else
            {
                ans += truckSize*val2;
                truckSize = 0;
            }
        }
        return ans;
    }
};
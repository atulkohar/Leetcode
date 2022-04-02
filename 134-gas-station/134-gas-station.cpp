class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0, cap = 0, total = 0;
        int n = gas.size();
        for(int i=0; i<n; i++)
        {
            cap += gas[i] - cost[i];
            if(cap < 0)
            {
                total += cap;
                ans = i+1;
                cap = 0;
            }
        }
        if(total + cap < 0)
            return -1;
        else
            return ans;
    }
};
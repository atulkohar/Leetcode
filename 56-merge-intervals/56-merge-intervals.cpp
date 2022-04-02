class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int n=intervals.size();
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>res[res.size()-1][1])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res[res.size()-1][1]=max(res[res.size()-1][1],intervals[i][1]);
            }
        }
        return res;
    }
};
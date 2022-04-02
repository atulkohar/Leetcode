class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for(int i=0; i<n; i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            unordered_map<double,int> m;
            int overLap = 1, tempAns=0;
            for(int j=i+1; j<n; j++)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1 == x2 and y1 == y2)
                    overLap++;
                else
                {
                    double slope = x1!=x2 ? ((1.0*(y2-y1))/(1.0*(x2-x1))):1e9;
                    tempAns = max(tempAns,++m[slope]);
                }
            }
            ans = max(ans,overLap+tempAns);
        }
        return ans;
    }
};
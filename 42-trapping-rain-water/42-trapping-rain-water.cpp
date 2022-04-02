class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> v1,v2(n);
        if(n < 3)
            return 0;
        v1.push_back(height[0]);
        int maxx=height[0];
        for(int i=1; i<n; i++)
        {
            maxx = max(maxx,height[i]);
            v1.push_back(maxx);
        }
        
        v2[n-1] = height[n-1];
        maxx=height[n-1];
        for(int i=n-2; i>=0; i--)
        {
            maxx = max(maxx,height[i]);
            v2[i] = maxx;
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans += abs(height[i] - min(v1[i],v2[i]));
        }
        cout<<endl;
        return ans;
    }
};
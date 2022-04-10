class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>>ans;
        for(int i = lo; i <= hi; i++) {
            int cnt = 0;
            int temp = i;
            while(temp > 1) {
                if(temp % 2 == 0) {
                    cnt++;
                    temp = temp / 2;
                }
                else {
                    cnt++;
                    temp = (3 * temp) + 1;
                }
            }
            ans.push_back({cnt,i});
        }
        sort(ans.begin(),ans.end());
        return ans[k - 1].second;        
    }
};
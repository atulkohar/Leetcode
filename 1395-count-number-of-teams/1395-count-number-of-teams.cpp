class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;
        for(int i=1; i<n-1; i++)
        {
            int leftless = 0, rightgreater = 0, leftgreater = 0, rightless = 0;
            for(int j=i-1; j>=0; j--)
            {
                if(rating[j]>rating[i])
                    leftgreater++;
                else
                    leftless++;
            }
            for(int j = i+1; j<n; j++)
            {
                if(rating[j]>rating[i])
                    rightgreater++;
                else
                    rightless++;
            }
            teams+=(leftless*rightgreater) + (leftgreater*rightless);
        }
        return teams;
    }
};
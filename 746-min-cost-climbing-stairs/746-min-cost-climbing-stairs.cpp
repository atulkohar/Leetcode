class Solution {
public:
    vector <int> cost;
    map <int, int> m;
    int minCostClimbingStairs(vector<int>& cost) {
        this->cost = cost;              //so that we dont need to pass it everytime we call dp function
        return min(dp(cost.size()-1), dp(cost.size()-2));       //because we can get our result by climbing the last stair(like in the example 2) or without climbing it (like in the example 1)
    }
    
    int dp(int i){
        if(i<2)         // base cases
            return m[i]=cost[i];
        
        if(m.find(i)==m.end())
            m[i]= min(dp(i-1), dp(i-2))+cost[i];        //recurrence relation
        
        return m[i];            //returns the min cost to climb uptil ith stair
    }
};
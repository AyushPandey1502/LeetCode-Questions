class Solution {
public:
    int minCost(int n, vector<int>& dp, vector<int>& cost){
        if(n <= 1) return cost[n]; 
        if(dp[n] != -1) return dp[n];
        return dp[n] = (n < cost.size() ? cost[n] : 0) + min(minCost(n-1, dp, cost), minCost(n-2, dp, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 
        vector<int> dp(n + 1, -1);
        return minCost(n, dp, cost);
    }
};

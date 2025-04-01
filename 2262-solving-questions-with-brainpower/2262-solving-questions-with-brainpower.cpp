class Solution {
public:
    long long mostPoints(vector<vector<int>>& ques) {
        int n = ques.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            long long take = ques[i][0]; 
            int index = i + ques[i][1] + 1; 
            if (index < n) take += dp[index];  
            long long notTake = dp[i + 1]; 
            dp[i] = max(take, notTake);
        }
        return dp[0];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target) > sum) return 0;

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));
        
        dp[0][sum] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= 2 * sum; j++) {
                if(dp[i - 1][j] != 0) {
                    dp[i][j + nums[i - 1]] += dp[i - 1][j];
                    dp[i][j - nums[i - 1]] += dp[i - 1][j];
                }
            }
        }
        return dp[n][sum + target];
    }
};

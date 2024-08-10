class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j <= n; j++) {
                dp[j] = max(dp[j], dp[j - i] * i);
            }
        }
        return dp[n];
    }
};
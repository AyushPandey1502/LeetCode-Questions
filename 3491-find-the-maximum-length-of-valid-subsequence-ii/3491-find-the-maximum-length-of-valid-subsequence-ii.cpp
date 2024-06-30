class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int N = nums.size();
        if (N == 0) return 0;
        vector<vector<int>> dp(N, vector<int>(k, 1));

        int maxLength = 1;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++) {
                int rem = (nums[i] + nums[j]) % k;
                dp[i][rem] = max(dp[i][rem], dp[j][rem] + 1);
                maxLength = max(maxLength, dp[i][rem]);
            }
        }
        return maxLength;
    }
};
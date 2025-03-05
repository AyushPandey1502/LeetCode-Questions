class Solution {
public:
    int findMaxProf(int index, vector<int>& prices, vector<vector<int>>& dp,
                    int flag) {
        if (index == dp.size())
            return 0;
        if (dp[index][flag] != -1)
            return dp[index][flag];
        if (flag == 1) {
            return dp[index][1] = max(-prices[index] +
                                          findMaxProf(index + 1, prices, dp, 0),
                                      findMaxProf(index + 1, prices, dp, 1));
        } else {
            return dp[index][0] = max(prices[index] +
                                          findMaxProf(index + 1, prices, dp, 1),
                                      findMaxProf(index + 1, prices, dp, 0));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return findMaxProf(0, prices, dp, 1);
    }
};
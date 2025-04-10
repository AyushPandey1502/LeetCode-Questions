class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s){
        return countValid(finish, limit, s) - countValid(start - 1, limit, s);
    }

    long long countValid(long long val, int limit, const string& suffix) {
        string numStr = to_string(val);
        int prefLen = numStr.length() - suffix.length();

        if (prefLen < 0) return 0;

        vector<vector<long long>> dp(prefLen + 1, vector<long long>(2, 0));

        dp[prefLen][0] = 1;
        dp[prefLen][1] = numStr.substr(prefLen) >= suffix ? 1 : 0;

        for (int i = prefLen - 1; i >= 0; --i) {
            int digit = numStr[i] - '0';
            dp[i][0] = (limit + 1) * dp[i + 1][0];

            if (digit <= limit) dp[i][1] = (long long)digit * dp[i + 1][0] + dp[i + 1][1];
            else dp[i][1] = (long long)(limit + 1) * dp[i + 1][0];
        }
        return dp[0][1];
    }
};
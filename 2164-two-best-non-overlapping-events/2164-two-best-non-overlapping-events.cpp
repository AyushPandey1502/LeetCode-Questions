class Solution {
public:
    int solve(int i, int k, vector<vector<int>>& e, vector<vector<int>>& dp) {
        if (k == 2) return 0;
        if (i >= e.size()) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        int nxt = upper_bound(e.begin(), e.end(), e[i][1],
                              [](int val, const vector<int>& event) {
                                  return val < event[0];
                              }) -
                  e.begin();
        int choose = e[i][2] + solve(nxt, k + 1, e, dp);
        int skip = solve(i + 1, k, e, dp);
        return dp[i][k] = max(choose, skip);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return solve(0, 0, events, dp);
    }
};
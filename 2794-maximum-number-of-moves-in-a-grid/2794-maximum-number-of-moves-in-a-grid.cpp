class Solution {
public:
    vector<vector<int>> dp;
    vector<int> X = {-1, 0, 1};
    vector<int> Y = {1, 1, 1};
    bool isBoundary(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i < n && j < m);
    }

    int maxMoves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int j = cols - 2; j >= 0; --j) {
            for (int i = 0; i < rows; ++i) {
                int maxMoves = 0;
                for (int d = -1; d <= 1; ++d) {
                    int ni = i + d;
                    int nj = j + 1;

                    if (ni >= 0 && ni < rows && grid[ni][nj] > grid[i][j]) {
                        maxMoves = max(maxMoves, 1 + dp[ni][nj]);
                    }
                }
                dp[i][j] = maxMoves;
            }
        }

        int result = 0;
        for (int i = 0; i < rows; ++i) {
            result = max(result, dp[i][0]);
        }
        return result;
    }
};
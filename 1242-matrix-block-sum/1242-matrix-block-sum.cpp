class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = mat[i - 1][j - 1] + prefix[i - 1][j] +
                               prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }

        vector<vector<int>> result(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int top = max(0, i - k), bottom = min(m - 1, i + k);
                int left = max(0, j - k), right = min(n - 1, j + k);
                result[i][j] = prefix[bottom + 1][right + 1] -
                            prefix[top][right + 1] - prefix[bottom + 1][left] +
                            prefix[top][left];
            }
        }
        return result;
    }
};
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> efforts(n, vector<int>(m, INT_MAX));
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        efforts[0][0] = 0;

        int drow[4] = {0, 0, 1, -1};
        int dcol[4] = {-1, 1, 0, 0};

        while (!q.empty()) {
            int eff = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newEff = max(eff, abs(heights[row][col] - heights[nrow][ncol]));
                    if (newEff < efforts[nrow][ncol]) {
                        efforts[nrow][ncol] = newEff;
                        q.push({newEff, {nrow, ncol}});
                    }
                }
            }
        }

        return efforts[n-1][m-1];
    }
};
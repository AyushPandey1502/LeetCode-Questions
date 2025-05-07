class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({0, {0, 0}});

        vector<int> directions = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
            auto [time, cell] = pq.top();
            int row = cell.first, col = cell.second;
            pq.pop();

            if (row == n - 1 && col == m - 1) {
                return time;
            }

            for (int d = 0; d < 4; ++d) {
                int nrow = row + directions[d];
                int ncol = col + directions[d + 1];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int waitTime = max(time + 1, moveTime[nrow][ncol] + 1);
                    if (waitTime < minTime[nrow][ncol]) {
                        minTime[nrow][ncol] = waitTime;
                        pq.push({waitTime, {nrow, ncol}});
                    }
                }
            }
        }

        return -1;
    }
};

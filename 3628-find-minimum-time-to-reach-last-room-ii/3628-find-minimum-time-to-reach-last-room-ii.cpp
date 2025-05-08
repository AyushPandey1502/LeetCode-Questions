class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));
        dist[0][0][0] = 0;
        
        priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<>> pq;
        pq.push({0, {0, 0, 0}});
        
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!pq.empty()) {
            auto [currTime, currPos] = pq.top();
            int x = currPos[0], y = currPos[1], parity = currPos[2];
            pq.pop();
            
            if (currTime > dist[x][y][parity]) continue;
            
            for (auto [dx, dy] : directions) {
                int nrow = x + dx;
                int ncol = y + dy;
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int newTime = max(currTime, moveTime[nrow][ncol]) + (parity ? 2 : 1);
                    
                    if (newTime < dist[nrow][ncol][!parity]) {
                        dist[nrow][ncol][!parity] = newTime;
                        pq.push({newTime, {nrow, ncol, !parity}});
                    }
                }
            }
        }
        
        return min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    }
};
class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({0, {i, j}});
                    visited[i][j] = 1;
                }
            }
        }
        int result = 0;
        while(!q.empty()){
            int time = q.front().first;
            int x = q.front().second.first, y = q.front().second.second;
            result = max(result, time);
            q.pop();
            for(auto it : dir){
                int nx = x + it.first, ny = y + it.second;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny] && grid[nx][ny] == 1){
                    visited[nx][ny] = 1;
                    q.push({time + 1, {nx, ny}});
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !visited[i][j]) return -1;
            }
        }
        return result;
    }
};
class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;
        int result = 0;

        while(!pq.empty()){
            auto [elev, row, col] = pq.top(); 
            pq.pop();
            result = max(result, elev);

            if(row == n-1 && col == n-1) return result;

            for(auto d : dir){
                int nrow = row + d[0], ncol = col + d[1];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !visited[nrow][ncol]){
                    visited[nrow][ncol] = 1;
                    pq.push({grid[nrow][ncol], nrow, ncol});
                }
            }
        }
        return result;
    }
};

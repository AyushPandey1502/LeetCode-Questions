class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size();
        if(m == 0) return 0;
        int n = board[0].size();
        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            if(board[i][0] == 1) q.push({i,0});
            if(board[i][n-1] == 1) q.push({i,n-1});
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 1) q.push({0,j});
            if(board[m-1][j] == 1) q.push({m-1,j});
        }

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if(board[x][y] != 1) continue;
            board[x][y] = 0;
            for(auto it : dir) {
                int nx = x + it.first, ny = y + it.second;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 1)
                    q.push({nx, ny});
            }
        }
        int result = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 1) result++;
            }
        }
        return result;
    }
};
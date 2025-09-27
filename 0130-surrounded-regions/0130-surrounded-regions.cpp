class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O') q.push({i,0});
            if(board[i][n-1] == 'O') q.push({i,n-1});
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O') q.push({0,j});
            if(board[m-1][j] == 'O') q.push({m-1,j});
        }

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if(board[x][y] != 'O') continue;
            board[x][y] = 'B';
            for(auto it : dir) {
                int nx = x + it.first, ny = y + it.second;
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O')
                    q.push({nx, ny});
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'B') board[i][j] = 'O';
            }
        }
    }
};

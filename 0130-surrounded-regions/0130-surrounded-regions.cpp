class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                visited[i][0] = 1;
            }
            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                visited[i][m - 1] = 1;
            }
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                q.push({0, j});
                visited[0][j] = 1;
            }
            if (board[n - 1][j] == 'O') {
                q.push({n - 1, j});
                visited[n - 1][j] = 1;
            }
        }

        int drow[] = {-1, 1, 0, 0};
        int dcol[] = {0, 0, 1, -1};
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
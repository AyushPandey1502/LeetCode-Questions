class Solution {
public:
    int drow[4] = {-1, 1, 0, 0};
    int dcol[4] = {0, 0, 1, -1};

    void dfs(int row, int col, vector<vector<char>>& board,
             vector<vector<int>>& visited) {
        visited[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, board, visited);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            if (!visited[i][0] && board[i][0] == 'O') {
                dfs(i, 0, board, visited);
            }
            if (!visited[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, board, visited);
            }
        }
        for (int i = 0; i < m; i++) {
            if (!visited[0][i] && board[0][i] == 'O') {
                dfs(0, i, board, visited);
            }
            if (!visited[n - 1][i] && board[n - 1][i] == 'O') {
                dfs(n - 1, i, board, visited);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board) {
        for (int i = row; i >= 0; i--) {
            if (board[i][col] == 'Q') return false;
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void findPos(int row, vector<string>& board, vector<vector<string>>& result) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }
        for (int j = 0; j < board.size(); j++) {
            if (isSafe(row, j, board)) {
                board[row][j] = 'Q';
                findPos(row + 1, board, result);
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;
        findPos(0, board, result);
        return result;
    }
};

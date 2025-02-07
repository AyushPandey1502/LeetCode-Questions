class Solution {
public:
    vector<vector<string>> result;

    bool isSafe(int row, int col, vector<string>& board) {
        for(int i = row - 1; i >= 0; i--) {
            if(board[i][col] == 'Q') return false;
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }

    void solveNQueen(int row, int n, vector<string>& board) {
        if(row == n) {
            result.push_back(board);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(isSafe(row, i, board)) {
                board[row][i] = 'Q';
                solveNQueen(row + 1, n, board);
                board[row][i] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        result.clear();
        vector<string> board(n, string(n, '.'));
        solveNQueen(0, n, board);
        return result.size();
    }
};

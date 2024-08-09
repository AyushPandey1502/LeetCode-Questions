class Solution {
public:
    bool checkMagicSquare(int row, int col, vector<vector<int>>& grid) {
        unordered_set<int> set;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int num = grid[row + i][col + j];
                if (num < 1 || num > 9 || set.find(num) != set.end()) {
                    return false;
                } else {
                    set.insert(num);
                }
            }
        }

        int sum = grid[row][col] + grid[row][col + 1] + grid[row][col + 2];
        for (int i = 0; i < 3; i++) {
            int rowSum = grid[row + i][col] + grid[row + i][col + 1] +
                         grid[row + i][col + 2];
            int colSum = grid[row][col + i] + grid[row + 1][col + i] +
                         grid[row + 2][col + i];
            if (rowSum != sum || colSum != sum) {
                return false;
            }
        }
        int diagSum =
            grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2];
        if (diagSum != sum)
            return false;

        int antiDiagSum =
            grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col];
        if (antiDiagSum != sum)
            return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n < 3 || m < 3)
            return 0;

        int count = 0;
        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                if (checkMagicSquare(i, j, grid)) {
                    count++;
                }
            }
        }
        return count;
    }
};
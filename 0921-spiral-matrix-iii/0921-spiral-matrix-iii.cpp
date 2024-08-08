class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        result.push_back({rStart, cStart});
        int drow[4] = {0, 1, 0, -1};
        int dcol[4] = {1, 0, -1, 0};
        int dir = 0;
        int steps = 0;

        while (result.size() < rows * cols) {
            if (dir == 0 || dir == 2) steps++;
            for (int i = 0; i < steps; i++) {
                int nrow = rStart + drow[dir];
                int ncol = cStart + dcol[dir];
                if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols) {
                    result.push_back({nrow, ncol});
                }
                rStart = nrow;
                cStart = ncol;
            }
            dir = (dir + 1) % 4;
        }
        return result;
    }
};
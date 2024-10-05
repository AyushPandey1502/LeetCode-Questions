class Solution {
public:
    int drow[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dcol[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    bool checkGrid(int row, int col, vector<vector<int>>& grid, int count) {
        if (count == grid.size() * grid.size() - 1) return true;  
        for (int i = 0; i < 8; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid.size()) {
                if (grid[nrow][ncol] == count + 1) {  
                    if (checkGrid(nrow, ncol, grid, count + 1)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0) return false; 
        int count = 0;
        return checkGrid(0, 0, grid, count);
    }
};

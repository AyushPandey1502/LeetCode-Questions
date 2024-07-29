class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> result(n, vector<int>(m, 0)); 
        for(int i = 0; i < n; i++){
            int onesRow = 0;
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) onesRow++;
            }
            for(int j = 0; j < m; j++){
                result[i][j] += 2 * onesRow - m;  
            }
        }
        for(int j = 0; j < m; j++){  
            int onesCol = 0;
            for(int i = 0; i < n; i++){  
                if(grid[i][j] == 1) onesCol++;
            }
            for(int i = 0; i < n; i++){  
                result[i][j] += 2 * onesCol - n; 
            }
        }
        return result;
    }
};
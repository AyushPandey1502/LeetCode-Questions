class neighborSum {
public:
    int n;
    vector<vector<int>> grid;
    
    neighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        this->grid = grid;
    }
    
    int adjacentSum(int value) {
        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == value) {
                    if(i > 0) result += grid[i-1][j]; 
                    if(i < n-1) result += grid[i+1][j];
                    if(j > 0) result += grid[i][j-1];
                    if(j < n-1) result += grid[i][j+1];
                    return result;
                }
            }
        }
        return result;
    }
    
    int diagonalSum(int value) {
        int result = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == value) {
                    if(i > 0 && j > 0) result += grid[i-1][j-1]; 
                    if(i > 0 && j < n-1) result += grid[i-1][j+1]; 
                    if(i < n-1 && j > 0) result += grid[i+1][j-1]; 
                    if(i < n-1 && j < n-1) result += grid[i+1][j+1]; 
                    return result;
                }
            }
        }
        return result;
    }
};
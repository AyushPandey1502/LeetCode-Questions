class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (m * n != original.size()) return {}; 

        vector<vector<int>> grid(m, vector<int>(n));
        for(int k = 0; k < m * n; k++){
            int i = k / n;  
            int j = k % n; 
            grid[i][j] = original[k];
        }
        return grid;
    }
};

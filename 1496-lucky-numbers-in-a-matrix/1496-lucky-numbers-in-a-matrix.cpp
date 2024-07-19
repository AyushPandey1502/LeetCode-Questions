class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        
        vector<int> rowMins(m, INT_MAX);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                rowMins[i] = min(rowMins[i], matrix[i][j]);
            }
        }
        
        for(int j = 0; j < n; j++) {
            int colMax = INT_MIN;
            for(int i = 0; i < m; i++) {
                colMax = max(colMax, matrix[i][j]);
            }
            for(int i = 0; i < m; i++) {
                if(matrix[i][j] == rowMins[i] && matrix[i][j] == colMax) {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        
        return result;
    }
};

class Solution {
public:
    bool checkLuckiness(vector<vector<int>>& matrix, int m, int n, int row, int col){
        for(int i = 0; i < m; i++){
            if(matrix[i][col] > matrix[row][col]) return false;
        }
        for(int j = 0; j < n; j++){
            if(matrix[row][j] < matrix[row][col]) return false;
        }
        return true;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        if(m == 0) return result;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(checkLuckiness(matrix, m, n, i, j)){
                    result.push_back(matrix[i][j]);
                }
            }
        }
        return result;
    }
};
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int countNeg = 0;
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] < 0){
                    countNeg++;
                    matrix[i][j] = abs(matrix[i][j]);
                }
            }
        }
        long long totalSum = 0;
        vector<int> col;
        for(auto it : matrix){
            sort(it.begin(), it.end());
            totalSum += accumulate(it.begin(), it.end(), 0);
            col.push_back(it[0]);
        }
        sort(col.begin(), col.end());
        if(countNeg % 2 == 1){
            totalSum -= (2 * col[0]);
        }
        return totalSum;
    }
};
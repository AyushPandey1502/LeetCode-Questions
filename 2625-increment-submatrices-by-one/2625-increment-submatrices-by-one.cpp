class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> diff(n+1, vector<int>(n+1, 0));
        for(auto it : queries){
            int x1 = it[0], y1 = it[1];
            int x2 = it[2], y2 = it[3];
            diff[x1][y1]++;
            diff[x1][y2+1]--;
            diff[x2+1][y1]--;
            diff[x2+1][y2+1]++;
        }
        vector<vector<int>> result(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i > 0) diff[i][j] += diff[i-1][j];
                if(j > 0) diff[i][j] += diff[i][j-1];
                if(i > 0 && j > 0) diff[i][j] -= diff[i-1][j-1];
                result[i][j] = diff[i][j];
            }
        }
        return result;
    }
};
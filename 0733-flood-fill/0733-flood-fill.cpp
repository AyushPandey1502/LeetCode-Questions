class Solution {
public:
    int drow[4] = {-1, 1, 0, 0};
    int dcol[4] = {0, 0, 1, -1};

    void dfs(int row, int col, vector<vector<int>>& image,
             vector<vector<int>>& result, int color, int startColor) {
        int n = image.size();
        int m = image[0].size();
        result[row][col] = color;
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == startColor &&
                result[nrow][ncol] != color) {
                dfs(nrow, ncol, image, result, color, startColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,                        int color) {
        int startColor = image[sr][sc];

        vector<vector<int>> result = image;
        dfs(sr, sc, image, result, color, startColor);
        return result;
    }
};
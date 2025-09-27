class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int clr = image[sr][sc];
        if (clr == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            for (auto it : dir) {
                int nx = x + it.first, ny = y + it.second;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                    image[nx][ny] == clr) {
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        }
        return image;
    }
};
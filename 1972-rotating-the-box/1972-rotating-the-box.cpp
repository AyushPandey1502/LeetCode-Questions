class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int ROWS = box.size();
        int COLS = box[0].size();
        
        vector<vector<char>> result(COLS, vector<char>(ROWS, '.'));
        
        for (int r = 0; r < ROWS; r++) {
            int i = COLS - 1;
            for (int c = COLS - 1; c >= 0; c--) {
                if (box[r][c] == '#') {
                    result[i][ROWS - r - 1] = '#';
                    i--;
                }
                else if (box[r][c] == '*') {
                    result[c][ROWS - r - 1] = '*';
                    i = c - 1;
                }
            }
        }
        return result;
    }
};
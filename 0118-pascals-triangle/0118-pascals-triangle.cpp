class Solution {
public:
    vector<int> generateRow(int row) {
        long long num = 1;
        vector<int> temp;
        temp.push_back(1);
        for (int col = 1; col < row; col++) {
            num = num * (row - col);
            num = num / col;
            temp.push_back(num);
        }
        return temp;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int row = 1; row <= numRows; row++) {
            result.push_back(generateRow(row));
        }
        return result;
    }
};

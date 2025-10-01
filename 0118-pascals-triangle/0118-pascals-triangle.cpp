class Solution {
public:
    vector<int> generateRows(int row){
        long long num = 1;
        vector<int> result;
        result.push_back(1);
        for(int col = 1; col < row; col++){
            num = num * (row-col);
            num /= col;
            result.push_back(num);
        }
        return result;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int row = 1; row <= numRows; row++){
            result.push_back(generateRows(row));
        }
        return result;
    }
};
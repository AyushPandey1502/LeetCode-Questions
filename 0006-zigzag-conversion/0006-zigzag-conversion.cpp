class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int row = 0, dir = -1;
        vector<string> order(numRows, "");
        for(int i = 0; i < s.size(); i++){
            order[row] += s[i];
            if(row == numRows - 1 || row == 0) dir *= -1;
            row += dir;
        }
        string result = "";
        for(auto it : order) result += it;
        return result;
    }
};
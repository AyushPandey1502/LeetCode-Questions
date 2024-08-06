class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, vector<char>> map = {
            {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}}, {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}
        };

        vector<string> result;
        result.push_back("");

        for (char digit : digits) {
            vector<string> temp;
            for (string str : result) {
                for (char ch : map[digit]) {
                    temp.push_back(str + ch);
                }
            }
            result.swap(temp);
        }
        return result;
    }
};
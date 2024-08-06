class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, vector<char>> map = {
            {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}}, {'4', {'g', 'h', 'i'}},
            {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}},
            {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}
        };

        unordered_set<string> set;
        set.insert("");

        for (int i = 0; i < digits.size(); i++) {
            vector<char> vec = map[digits[i]];
            unordered_set<string> temp;

            for (auto str : set) {
                for (auto it : vec) {
                    temp.insert(str + it);
                }
            }
            set = move(temp);
        }
        return vector<string>(set.begin(), set.end());
    }
};
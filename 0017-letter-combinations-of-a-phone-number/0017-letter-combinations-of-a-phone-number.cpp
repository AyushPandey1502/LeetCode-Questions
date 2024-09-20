class Solution {
public:
    vector<string> dig = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void generateComb(int i, string& digits, string current, vector<string>& result) {
        if (i == digits.size()) {
            result.push_back(current);
            return;
        }
        for (char ch : dig[digits[i] - '0']) {
            generateComb(i + 1, digits, current + ch, result);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        generateComb(0, digits, "", result);
        return result;
    }
};

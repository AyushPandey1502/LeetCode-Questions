class Solution {
public:
    void backtrack(int n, string& current, vector<string>& result) {
        if (current.size() == n) {
            result.push_back(current);
            return;
        }
        current.push_back('1');
        backtrack(n, current, result);
        current.pop_back();

        if (current.empty() || current.back() == '1') {
            current.push_back('0');
            backtrack(n, current, result);
            current.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> result;
        string current;
        backtrack(n, current, result);
        return result;
    }
};

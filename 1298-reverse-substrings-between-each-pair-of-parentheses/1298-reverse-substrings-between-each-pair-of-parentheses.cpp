class Solution {
public:
    string reverseParentheses(string s) {
        deque<int> stack;
        vector<char> result;

        for (char x : s) {
            if (x == '(') {
                stack.push_back(result.size());
            } else if (x == ')') {
                int start = stack.back();
                stack.pop_back();
                reverse(result.begin() + start, result.end());
            } else {
                result.push_back(x);
            }
        }
        return string(result.begin(), result.end());
    }
};
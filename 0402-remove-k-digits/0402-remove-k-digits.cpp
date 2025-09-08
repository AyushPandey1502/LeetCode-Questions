class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while (k-- > 0 && !st.empty()) st.pop();
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        while (!result.empty() && result.back() == '0') {
            result.pop_back();
        }
        reverse(result.begin(), result.end());
        return result.empty() ? "0" : result;
    }
};

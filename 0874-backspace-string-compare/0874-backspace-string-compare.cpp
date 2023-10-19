class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string S, T;
        for (char c : s) {
            if (c == '#') {
                if (!S.empty()) {
                    S.pop_back();
                }
            } else {
                S += c;
            }
        }
        for (char c : t) {
            if (c == '#') {
                if (!T.empty()) {
                    T.pop_back();
                }
            } else {
                T += c;
            }
        }
        return S == T;
    }
};

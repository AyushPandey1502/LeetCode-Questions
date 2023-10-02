class Solution {
public:
    string truncateSentence(string s, int k) {
        int i = 0;
        for (; i < s.length(); i++) {
            if (s[i] == ' ' && --k == 0) {
                break;
            }
        }
        return s.substr(0, i);
    }
};

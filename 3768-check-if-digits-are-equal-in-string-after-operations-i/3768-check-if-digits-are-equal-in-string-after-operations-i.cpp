class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string num;
            num.reserve(s.size() - 1);
            for (size_t i = 0; i < s.size() - 1; ++i) {
                num += '0' + ((s[i] - '0') + (s[i + 1] - '0')) % 10;
            }
            s = move(num);
        }
        return s.size() == 2 && s[0] == s[1];
    }
};
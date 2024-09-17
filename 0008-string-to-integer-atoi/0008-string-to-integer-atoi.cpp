class Solution {
public:

    long recursiveAtoi(const string& s, int i, int sign, long result) {
        if (i >= s.size() || !isdigit(s[i])) {
            return result * sign;
        }
        result = result * 10 + (s[i] - '0');
        if (result * sign > INT_MAX) return INT_MAX;
        if (result * sign < INT_MIN) return INT_MIN;
        return recursiveAtoi(s, i + 1, sign, result);
    }
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        long result = recursiveAtoi(s, i, sign, 0);
        return static_cast<int>(result);
    }
};

class Solution {
public:
    int myAtoi(string s) {
        long long result = 0;
        int sign = 1;
        bool started = false; 
        
        for (char c : s) {
            if (!started && c == ' ') {
                continue;
            } else if (!started && (c == '-' || c == '+')) {
                sign = (c == '-') ? -1 : 1;
                started = true; 
            } else if (isdigit(c)) {
                started = true;
                result = result * 10 + (c - '0');

                if (sign == 1 && result > INT_MAX) return INT_MAX;
                if (sign == -1 && -result < INT_MIN) return INT_MIN;
            } else {
                break;
            }
        }
        
        return sign * result;
    }
};

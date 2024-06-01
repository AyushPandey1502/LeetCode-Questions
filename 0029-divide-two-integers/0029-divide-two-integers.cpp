// Time Complexity : O((logn)^2)
// Space Complexity : O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        int sign = 1;
        if (divisor > 0 && dividend <= 0)
            sign = -1;
        if (divisor < 0 && dividend >= 0)
            sign = -1;
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long result = 0;
        long d = abs(divisor);
        long n = abs(dividend);
        while (n >= d) {
            int count = 0;
            while (n > (d * (static_cast<long long>(1) << count + 1)))
                count++;
            n -= (d << count);
            result += 1 << count;
        }

        if (result == (1 << 31) && (sign > 0))
            return INT_MAX + 1;
        if (result == (1 << 31) && (sign < 0))
            return INT_MIN;
        return sign * result;
    }
};
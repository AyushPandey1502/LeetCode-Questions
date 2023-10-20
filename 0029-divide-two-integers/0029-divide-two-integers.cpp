class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        long long ldividend = llabs(static_cast<long long>(dividend));
        long long ldivisor = llabs(static_cast<long long>(divisor));

        long long quotient = 0;
        long long temp = 0;

        for (int i = 31; i >= 0; i--) {
            if ((temp + (ldivisor << i)) <= ldividend) {
                temp += ldivisor << i;
                quotient |= 1LL << i;
            }
        }
        if (sign == -1 && quotient > static_cast<long long>(INT_MAX)) {
            return INT_MIN;
        } else if (sign == 1 && quotient > static_cast<long long>(INT_MAX) - 1) {
            return INT_MAX;
        }
        return static_cast<int>(sign * quotient);
    }
};

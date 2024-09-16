class Solution {
public:
    double myPow(double x, int n) {
        double result = 1;
        long num = n;
        if (n < 0) {
            num = -num;
            x = 1 / x;
        }
        while (num > 0) {
            if (num % 2 == 1) {
                result *= x;
                num--;
            } else {
                x = x * x;
                num = num / 2;
            }
        }
        return result;
    }
};
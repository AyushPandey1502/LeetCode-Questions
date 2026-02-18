class Solution {
public:
    bool hasAlternatingBits(int n) {
        int bit = n % 2;
        n /= 2;
        while (n > 0) {
            if (bit == n % 2) return false;
            bit = n % 2;
            n /= 2;
        }
        return true;
    }
};
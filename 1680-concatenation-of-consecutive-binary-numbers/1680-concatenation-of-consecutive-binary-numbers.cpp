class Solution {
public:
    static int concatenatedBinary(int n) {
        constexpr int MOD = 1e9 + 7;
        uint64_t result = 0;
        for (unsigned x = 1; x <= n; x++) {
            const int bw = 32 - countl_zero(x);
            result = (result << bw) + x;
            if (result >= MOD) result %= MOD;
        }
        return result;
    }
};
class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfWays(int n) {
        long long x = 6, y = 6;
        for (int i = 2; i <= n; i++) {
            long long nx = (3 * x + 2 * y) % MOD;
            long long ny = (2 * x + 2 * y) % MOD;
            x = nx;
            y = ny;
        }
        return (x + y) % MOD;
    }
};
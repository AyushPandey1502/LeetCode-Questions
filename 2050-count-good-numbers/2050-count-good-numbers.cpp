class Solution {
public:
    const long MOD = 1e9 + 7;
    long long power(int x, long long n) {
        if (n == 0) return 1;
        if (n % 2 == 1) {
            return (x * power(x, n - 1)) % MOD;
        }
        long long half = power(x, n / 2);
        return (half * half) % MOD;
    }

    int countGoodNumbers(long long n) {
        long long oddExp = n / 2;
        long long evenExp = (n + 1) / 2;
        return (power(5, evenExp) * power(4, oddExp)) % MOD;
    }
};

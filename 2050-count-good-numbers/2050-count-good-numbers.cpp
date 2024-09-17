class Solution {
public:
    const long MOD = 1e9 + 7;
    
    long long modPow(long long base, long long exp, long long mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;
        long long evenCount = modPow(5, evenPos, MOD);
        long long oddCount = modPow(4, oddPos, MOD);
        
        return (evenCount * oddCount) % MOD;
    }
};

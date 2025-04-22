class Solution {
public:
    using ll = long long;
    ll M = 1e9 + 7;
    const static ll MOD = 1e9 + 7;
    const static ll MAXN = 1e6;

    ll fact[MAXN + 1];
    ll ifact[MAXN + 1];

    int power(int base, int exp, int mod) {
        ll result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (1LL * result * base) % mod;
            }
            base = (1LL * base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    void factorials(int n, int mod) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = (1LL * fact[i - 1] * i) % mod;
        }

        ifact[n] = power(fact[n], mod - 2, mod);
        for (int i = n - 1; i >= 0; --i) {
            ifact[i] = (1LL * ifact[i + 1] * (i + 1)) % mod;
        }
    }

    ll nCr_mod(int n, int r, int mod) {
        if (r < 0 || r > n) return 0;
        ll num = fact[n];
        ll denom = (1LL * ifact[r] * ifact[n - r]) % mod;
        return (1LL * num * denom) % mod;
    }

    int idealArrays(int n, int maxValue) {
        vector<vector<ll>> dp(15, vector<ll>(maxValue + 1));
        for (int j = 1; j <= maxValue; j++) dp[1][j] = 1;

        for (int i = 2; i < 15; i++) {
            for (int j = 1; j <= maxValue; j++) {
                ll mul = 2 * j;
                while (mul <= maxValue) {
                    dp[i][j] += dp[i - 1][mul];
                    dp[i][j] %= M;
                    mul += j;
                }
            }
        }

        ll result = 0;
        factorials(n - 1, M);

        for (int i = 1; i <= 14; i++) {
            for (int j = 1; j <= maxValue; j++) {
                result += dp[i][j] * nCr_mod(n - 1, i - 1, M);
                result %= M;
            }
        }

        return result;
    }
};

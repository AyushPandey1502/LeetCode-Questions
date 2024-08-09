// SIEVE OF ERATOSTHENES   
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<bool> primes(n + 1, true);
        for (int p = 2; p * p <= n; p++) {
            if (primes[p] == true) {
                for (int i = p * p; i <= n; i += p) {
                    primes[i] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (primes[i]) count++;
        }
        return count;
    }
};
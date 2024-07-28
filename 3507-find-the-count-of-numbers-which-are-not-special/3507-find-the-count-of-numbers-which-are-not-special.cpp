class Solution {
public:
    vector<int> sieve(int num) {
        vector<bool> is_prime(num + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= num; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= num; j += i) {
                    is_prime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = 2; i <= num; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }

    int nonSpecialCount(int l, int r) {
        int max_sqrt = sqrt(r);
        vector<int> primes = sieve(max_sqrt);
        unordered_set<int> specialNum;
        for (int prime : primes) {
            int square = prime * prime;
            if (square >= l && square <= r) {
                specialNum.insert(square);
            }
        }

        int totalNumbers = r - l + 1;
        int specialCount = specialNum.size();
        int nonSpecialCount = totalNumbers - specialCount;

        return nonSpecialCount;
    }
};
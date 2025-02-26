class Solution {
public:
    vector<int> primes;

    void sieve() {
        vector<bool> is_prime(1e5 + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i * i <= 1e5; i++) {
            if (is_prime[i]) {
                for (int p = i * i; p <= 1e5; p += i) {
                    is_prime[p] = false;
                }
            }
        }
        for (int i = 2; i <= 1e5; i++) {
            if (is_prime[i]) primes.push_back(i);
        }
    }

    vector<int> findDivisors(int num) {
        vector<int> divisors;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                divisors.push_back(i);
                if (i != num / i) {
                    divisors.push_back(num / i);
                }
            }
        }
        return divisors;
    }

    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        sieve();
        
        for (int num : nums) {
            vector<int> divisors = findDivisors(num);
            if (divisors.size() == 4) {
                result += accumulate(divisors.begin(), divisors.end(), 0);
            }
        }
        return result;
    }
};
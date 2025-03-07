class Solution {
public:
    static bitset<1000001> is_prime;
    
    Solution() { 
        if (!is_prime[2]) sieve();
    }

    void sieve() {
        is_prime.set();
        is_prime[0] = is_prime[1] = 0;
        for (int i = 2; i * i <= 1e6; i++) {
            if (is_prime[i]) {
                for (int p = i * i; p <= 1e6; p += i) 
                    is_prime[p] = 0;
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        int prev = -1, num1 = -1, num2 = -1, minDiff = INT_MAX;
        
        for (int i = left; i <= right; i++) {
            if (is_prime[i]) {
                if (prev != -1 && i - prev < minDiff) {
                    minDiff = i - prev;
                    num1 = prev;
                    num2 = i;
                }
                prev = i;
            }
        }
        return num1 == -1 ? vector<int>{-1, -1} : vector<int>{num1, num2};
    }
};

bitset<1000001> Solution::is_prime;

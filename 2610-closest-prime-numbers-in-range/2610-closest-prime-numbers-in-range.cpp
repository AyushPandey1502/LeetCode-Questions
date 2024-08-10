class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if (right < 2) return {-1, -1};

        vector<bool> primes(right + 1, true);
        primes[0] = primes[1] = false;

        for (int p = 2; p * p <= right; p++) {
            if (primes[p]) {
                for (int i = p * p; i <= right; i += p) {
                    primes[i] = false;
                }
            }
        }

        vector<int> primeNum;
        for (int i = max(left, 2); i <= right; i++) {
            if (primes[i]) {
                primeNum.push_back(i);
            }
        }

        if (primeNum.size() <= 1) return {-1, -1};

        int index = 0;
        int minDiff = INT_MAX;
        for (int i = 1; i < primeNum.size(); i++) {
            if ((primeNum[i] - primeNum[i - 1]) < minDiff) {
                minDiff = primeNum[i] - primeNum[i - 1];
                index = i;
            }
        }

        return {primeNum[index - 1], primeNum[index]};
    }
};

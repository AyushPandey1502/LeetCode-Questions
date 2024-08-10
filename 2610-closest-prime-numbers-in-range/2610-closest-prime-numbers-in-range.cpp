class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> primes(right + 1, true);
        
        if (left == 1) {
            primes[1] = false;
            left = 2; 
        }
        
        for (int p = 2; p * p <= right; p++) {
            if (primes[p]) {
                int sm = max(p * p, (left + p - 1) / p * p);
                for (int i = sm; i <= right; i += p) {
                    primes[i] = false;
                }
            }
        }
        
        vector<int> primeNum;
        for (int i = left; i <= right; i++) {
            if (primes[i]) {
                primeNum.push_back(i);
            }
        }
        
        if (primeNum.size() <= 1) return {-1, -1};
        
        int index = -1;
        int minDiff = INT_MAX;
        for (int i = 1; i < primeNum.size(); i++) {
            if ((primeNum[i] - primeNum[i-1]) < minDiff) {
                minDiff = primeNum[i] - primeNum[i-1];
                index = i;
            }
        }
        return {primeNum[index-1], primeNum[index]};
    }
};

class Solution {
public:
    Solution() {
        vector<bool> primes(1001, true);
        primes[0] = primes[1] = false;
        for (int p = 2; p * p <= 1000; p++) {
            if (primes[p]) {
                for (int i = p * p; i <= 1000; i += p) {
                    primes[i] = false;
                }
            }
        }
        for (int i = 2; i <= 1000; i++) {
            if (primes[i]) primeNum.push_back(i);
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1]) {
                auto it = lower_bound(primeNum.begin(), primeNum.end(), nums[i] - (nums[i + 1] - 1));
                if (it == primeNum.end() || *it >= nums[i]) return false;
                nums[i] -= *it;
            }
        }
        return true;
    }

private:
    vector<int> primeNum;
};

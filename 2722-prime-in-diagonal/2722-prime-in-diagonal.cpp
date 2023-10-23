class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        int prime = 0;
        int n = nums.size();

        // Check the main diagonal.
        for (int i = 0; i < n; i++) {
            int num = nums[i][i];
            if (isPrime(num)) {
                prime = max(prime, num);
            }
        }
        for (int i = 0; i < n; i++) {
            int num = nums[i][n - i - 1];
            if (isPrime(num)) {
                prime = max(prime, num);
            }
        }

        return prime;
    }
};

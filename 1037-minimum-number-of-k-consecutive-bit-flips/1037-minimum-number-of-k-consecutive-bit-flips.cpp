class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, flips = 0;
        vector<int> flipIndicator(n, 0); 

        for (int i = 0; i < n; ++i) {
            if (i >= k) {
                flips ^= flipIndicator[i - k];
            }
            if (flips % 2 == nums[i]) {
                if (i + k > n) return -1; 
                flips ^= 1;
                flipIndicator[i] = 1;
                count++;
            }
        }
        return count;
    }
};

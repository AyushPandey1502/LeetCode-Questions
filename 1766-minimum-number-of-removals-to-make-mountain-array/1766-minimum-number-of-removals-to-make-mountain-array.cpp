class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), result = 1;
        vector<int> LIS(n, 1), LDS(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[i]) LDS[i] = max(LDS[i], 1 + LDS[j]);
            }
            if(LIS[i] > 1 && LDS[i] > 1) result = max(result, LIS[i] + LDS[i] - 1);
        }
        return n - result;
    }
};
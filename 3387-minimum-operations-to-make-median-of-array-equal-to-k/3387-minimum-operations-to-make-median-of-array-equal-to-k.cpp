class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int median = n / 2;
        long long count = 0;
        
        if (nums[median] == k) return 0; 
    
        if (nums[median] > k) {
            int j = median;
            while (j >= 0 && nums[j] > k) {
                count += nums[j--] - k;
            }
        } else {
            int j = median;
            while (j < n && nums[j] < k) {
                count += k - nums[j++];
            }
        }
        return count;
    }
};

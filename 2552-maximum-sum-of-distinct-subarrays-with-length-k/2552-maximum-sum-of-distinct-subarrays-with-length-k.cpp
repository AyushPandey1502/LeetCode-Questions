class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), left = 0, right = 0;
        long long sum = 0, maxSum = 0;
        unordered_map<int, int> map;
        while (right < n) {
            sum += nums[right];
            map[nums[right]]++;
            while (map[nums[right]] > 1) {
                map[nums[left]]--;
                sum -= nums[left];
                left++;
            }
            if (right - left + 1 == k) {
                maxSum = max(maxSum, sum);
                map[nums[left]]--;
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return maxSum;
    }
};

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int result = 0, left = 0;
        sort(nums.begin(), nums.end());
        for (int right = 0; right < nums.size(); right++) {
            int diff = nums[right] - nums[left];
            while (diff > 2 * k) {
                left++;
                diff = nums[right] - nums[left];
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
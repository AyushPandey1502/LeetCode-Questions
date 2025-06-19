class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 1, minVal = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] - minVal > k) {
                result++;
                minVal = nums[i];
            }
        }
        return result;
    }
};
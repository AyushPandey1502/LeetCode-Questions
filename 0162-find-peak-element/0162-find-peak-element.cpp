class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return maxElement(nums, 0, nums.size() - 1);
    }

    int maxElement(vector<int>& nums, int low, int high) {
        if (low == high) return low;
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1]) {
            return maxElement(nums, low, mid);
        } else {
            return maxElement(nums, mid + 1, high);
        }
    }
};

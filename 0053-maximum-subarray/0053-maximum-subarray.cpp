class Solution {
public:
    int crossingSum(vector<int>& nums, int low, int mid, int high) {
        int leftSum = INT_MIN, rightSum = INT_MIN, sum = 0;
        
        for (int i = mid; i >= low; i--) {
            sum += nums[i];
            leftSum = max(leftSum, sum);
        }
        
        sum = 0;
        for (int i = mid + 1; i <= high; i++) {
            sum += nums[i];
            rightSum = max(rightSum, sum);
        }
        
        return leftSum + rightSum;
    }

    int maxSum(vector<int>& nums, int low, int high) {
        if (low == high) return nums[low];

        int mid = low + (high - low) / 2;
        int leftSum = maxSum(nums, low, mid);
        int rightSum = maxSum(nums, mid + 1, high);
        int crossSum = crossingSum(nums, low, mid, high);

        return max({leftSum, rightSum, crossSum});
    }

    int maxSubArray(vector<int>& nums) {
        return maxSum(nums, 0, nums.size() - 1);
    }
};

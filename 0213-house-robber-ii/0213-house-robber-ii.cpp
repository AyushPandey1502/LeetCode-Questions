class Solution {
public:
    int nonAdjacentSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; i++){
            int pick = nums[i] + dp[i-2];
            int notPick = dp[i-1];
            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> nums1(nums.begin(), nums.begin() + n-1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        return max(nonAdjacentSum(nums1), nonAdjacentSum(nums2));
    }
};
class Solution {
public:
    int find(int i, int prev, vector<int>& nums, vector<vector<int>>& dp){
        if(i == nums.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        int result = find(i+1, prev, nums, dp);
        if(prev == -1 || nums[i] > nums[prev]){
            result = max(result, 1 + find(i+1, i, nums, dp));
        }
        return dp[i][prev + 1] = result;
    }

    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> dp(n, vector<int>(n+1, -1));
      return find(0, -1, nums, dp);
    }   
};
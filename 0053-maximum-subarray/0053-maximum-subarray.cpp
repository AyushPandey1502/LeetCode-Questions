class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0], n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum = max(sum + nums[i], nums[i]);
            result = max(result, sum);
        }
        return result;
    }
};
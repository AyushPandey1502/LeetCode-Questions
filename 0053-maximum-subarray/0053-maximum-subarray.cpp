class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0], sum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            sum = max(sum + nums[i], nums[i]);
            result = max(result, sum);
        }
        return result;
    }
};
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int result = 0;
        for(int i = 1; i < nums.size()-1; i++){
            int sum = nums[i-1] + nums[i+1];
            if(sum == (0.5 * nums[i])) result++;
        }
        return result;
    }
};
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), result = INT_MIN;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(nums[j] > nums[i]) result = max(result, nums[j]-nums[i]);
            }
        }
        return result == INT_MIN ? -1 : result;
    }
};
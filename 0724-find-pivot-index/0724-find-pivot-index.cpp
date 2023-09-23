class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++) { 
            if (leftSum == rightSum - nums[i]) return i;
            leftSum += nums[i];
            rightSum -= nums[i];
        }
        return -1;
    }
};

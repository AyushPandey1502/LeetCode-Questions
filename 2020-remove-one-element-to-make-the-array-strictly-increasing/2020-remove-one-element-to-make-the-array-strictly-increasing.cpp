class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] <= nums[i - 1]) {
                count++;
                if (count > 1) return false;
                if (i == 1 || nums[i] > nums[i - 2]) continue;
                if (i == n - 1 || nums[i + 1] > nums[i - 1]) continue;
                
                return false;
            }
        }
        return true;
    }
};
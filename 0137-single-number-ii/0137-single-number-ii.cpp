class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty()) {
            return -1; 
        }

        sort(nums.begin(), nums.end());

        if (nums.size() == 1 || nums[0] != nums[1]) {
            return nums[0];
        }

        for (int i = 1; i < nums.size(); ++i) {
            if (i == nums.size() - 1) {
                if (nums[i] != nums[i - 1]) {
                    return nums[i];
                }
            } else if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int originalSize = nums.size();
        for (int i = 0; i < originalSize; i++) {
            nums.push_back(nums[i]);
        }
        return nums;
    }
};

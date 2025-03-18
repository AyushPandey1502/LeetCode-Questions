class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0, right = 0, temp = 0, result = 0;

        while (right < nums.size()) {
            while ((temp & nums[right]) != 0) {
                temp ^= nums[left];
                left++;
            }
            temp |= nums[right];
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};

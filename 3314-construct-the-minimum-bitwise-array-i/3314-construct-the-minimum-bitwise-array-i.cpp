class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (auto &it : nums) {
            int result = -1;
            int d = 1;
            while ((it & d) != 0) {
                result = it - d;
                d <<= 1;
            }
            it = result;
        }
        return nums;
    }
};
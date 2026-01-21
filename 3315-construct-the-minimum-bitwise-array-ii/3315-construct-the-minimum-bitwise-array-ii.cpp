class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (int& x : nums) {
            int result = -1;
            int d = 1;
            while ((x & d) != 0) {
                result = x - d;
                d <<= 1;
            }
            x = result;
        }
        return nums;
    }
};
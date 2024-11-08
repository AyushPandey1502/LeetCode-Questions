class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> result(n);
        int maxK = (1 << maximumBit) - 1;
        int XOR = 0;
        for(int num : nums) {
            XOR ^= num;
        }
        for(int i = 0; i < n; i++) {
            result[i] = XOR ^ maxK;
            XOR ^= nums[n-i-1]; 
        }
        return result;
    }
};

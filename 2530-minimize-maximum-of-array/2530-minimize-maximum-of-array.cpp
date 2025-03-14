class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long long result = 0, prefixSum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            result = max(result, (prefixSum + i) / (i + 1));
        }
        
        return result;
    }
};
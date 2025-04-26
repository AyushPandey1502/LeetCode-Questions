class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        int n = nums.size();
        int leftBound = -1, minPos = -1, maxPos = -1;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) leftBound = i;
            if (nums[i] == minK) minPos = i;
            if (nums[i] == maxK) maxPos = i;
            result += max(0, min(minPos, maxPos) - leftBound);
        }
        return result;
    }
};

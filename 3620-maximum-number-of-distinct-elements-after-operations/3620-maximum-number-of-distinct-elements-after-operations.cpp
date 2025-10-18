class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int result = 0, prev = INT_MIN;
        for (int it : nums) {
            int curr = min(max(it - k, prev + 1), it + k);
            if (curr > prev) {
                result++;
                prev = curr;
            }
        }
        return result;
    }
};
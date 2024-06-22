class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> count(n + 1, 0);
        count[0] = 1;
        int result = 0, t = 0;
        for (int x : nums) {
            t += x & 1;
            if (t - k >= 0) {
                result += count[t - k];
            }
            count[t]++;
        }
        return result;
    }
};
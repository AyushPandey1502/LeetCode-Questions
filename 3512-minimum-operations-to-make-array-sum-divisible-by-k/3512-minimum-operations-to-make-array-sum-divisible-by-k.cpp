class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        return total % k;
    }
};
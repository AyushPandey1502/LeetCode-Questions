class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> set;
        for (int num : nums) {
            if (num > 0) set.emplace(num);
        }
        if (set.empty()) return *max_element(nums.begin(), nums.end());
        return accumulate(set.begin(), set.end(), 0);
    }
};
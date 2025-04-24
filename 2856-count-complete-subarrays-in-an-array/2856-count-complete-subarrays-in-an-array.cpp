class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set(nums.begin(), nums.end());
        int count = set.size();

        int result = 0;
        for (int i = 0; i < n; ++i) {
            unordered_set<int> temp;
            for (int j = i; j < n; ++j) {
                temp.insert(nums[j]);
                if (temp.size() == count) result++;
            }
        }
        return result;
    }
};

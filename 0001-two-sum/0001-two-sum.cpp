class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());
        int left = 0, right = n - 1;
        while (left <= right) {
            int sum = vec[left].first + vec[right].first;
            if (sum == target) {
                return {vec[left].second, vec[right].second};
            }
            if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return {-1, -1};
    }
};
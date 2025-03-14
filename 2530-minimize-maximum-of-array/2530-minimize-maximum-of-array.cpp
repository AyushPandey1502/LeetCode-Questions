class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        int result = right;

        auto check = [&](int mid) {
            long long extra = 0;
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] + extra > mid) {
                    extra = nums[i] + extra - mid;
                } else extra = 0;
            }
            return extra == 0;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                result = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return result;
    }
};

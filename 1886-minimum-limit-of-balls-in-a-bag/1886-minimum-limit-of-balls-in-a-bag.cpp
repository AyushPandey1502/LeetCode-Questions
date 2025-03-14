class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end()), result = right;

        auto check = [&](int mid) {
            int count = 0;
            for (int num : nums) {
                count += (num + mid - 1) / mid - 1;
                if (count > maxOperations) return false;
            }
            return count <= maxOperations;
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};

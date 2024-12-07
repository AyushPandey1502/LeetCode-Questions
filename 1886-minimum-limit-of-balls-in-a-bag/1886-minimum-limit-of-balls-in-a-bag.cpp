class Solution {
public:

    bool check(int mid, vector<int> &nums, int maxOperations) {
        int n = nums.size(); 
        for (auto num: nums) {
            maxOperations -= (num + mid - 1) / mid - 1;
        }
        return maxOperations >= 0; 
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int n = nums.size(); 
        int left = 1, right = 1e9; 
        int result = 1e9; 
        while (left <= right) {
            int mid = left + (right - left) / 2; 
            if (check(mid, nums, maxOperations)) {
                result = mid; 
                right = mid - 1; 
            } else {
                left = mid + 1; 
            }
        }
        return result; 
    }
};
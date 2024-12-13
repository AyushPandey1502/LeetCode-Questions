class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for (int left, right = 0; right < n; right += 2){
            left = right;
            while (right + 1 < n && nums[right] > nums[right + 1]) right++;
            for (int i = right; i >= left; i -= 2) sum += nums[i];
        }
        return sum;
    }
};
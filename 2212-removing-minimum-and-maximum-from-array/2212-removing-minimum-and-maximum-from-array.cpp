class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int minIndex = 0;
        int maxIndex = 0;
        int N = nums.size();
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (nums[i] > maxNum) {
                maxNum = nums[i];
                maxIndex = i;
            }
            if (nums[i] < minNum) {
                minNum = nums[i];
                minIndex = i;
            }
        }
        int fromFront = max(minIndex, maxIndex) + 1;
        int fromBack = max(N - minIndex, N - maxIndex);
        int mixed = min(minIndex, maxIndex) + 1 + min(N - minIndex, N - maxIndex);
        return min({fromFront, fromBack, mixed});
    }
};

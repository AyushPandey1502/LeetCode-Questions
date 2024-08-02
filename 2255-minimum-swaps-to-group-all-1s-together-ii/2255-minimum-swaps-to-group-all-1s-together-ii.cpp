class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int countOnes = accumulate(nums.begin(), nums.end(), 0);
        int currentCount = 0;
        for (int i = 0; i < countOnes; i++) {
            if (nums[i] == 1)
                currentCount++;
        }
        int result = countOnes - currentCount;
        for (int i = countOnes; i < countOnes + n; i++) {
            currentCount =
                currentCount - nums[(i - countOnes) % n] + nums[i % n];
            result = min(result, countOnes - currentCount);
        }

        return result;
    }
};

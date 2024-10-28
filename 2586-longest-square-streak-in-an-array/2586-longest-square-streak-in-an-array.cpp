class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int result = -1;
        unordered_set<int> numSet(nums.begin(), nums.end());
        vector<int> sortedNums(numSet.begin(), numSet.end());
        sort(sortedNums.begin(), sortedNums.end());
        
        for (int num : sortedNums) {
            long long curr = num;
            int count = 0;
            
            while (numSet.count(curr)) {
                numSet.erase(curr);
                curr *= curr;
                count++;
            }
            result = max(result, count);
        }
        return result > 1 ? result : -1;
    }
};
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();
        unordered_map<int, int> diffCount;
        for(int i = 0; i < n; i++){
            int diff = i - nums[i];
            int goodPairs = diffCount[diff];
            result += i - goodPairs;
            diffCount[diff] = goodPairs + 1;
        }
        return result;
    }
};
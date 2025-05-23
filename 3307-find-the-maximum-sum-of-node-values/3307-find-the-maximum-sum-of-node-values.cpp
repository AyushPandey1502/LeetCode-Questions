class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long result = 0;
        int minChange = INT_MAX;
        int gainCount = 0;

        for (auto it : nums) {
            int gain = (it ^ k) - it;
            if (gain > 0) {
                result += (it ^ k);
                gainCount++;
                minChange = min(minChange, gain);
            } else {
                result += it;
                minChange = min(minChange, -gain);
            }
        }
        if (gainCount % 2 == 1) result -= minChange;
        return result;
    }
};
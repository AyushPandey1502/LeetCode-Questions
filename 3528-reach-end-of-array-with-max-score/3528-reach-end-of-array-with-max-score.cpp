class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long result = 0;
        int maxElem = 0;
        for (int it : nums) {
            result += maxElem;
            maxElem = max(maxElem, it);
        }
        return result;
    }
};

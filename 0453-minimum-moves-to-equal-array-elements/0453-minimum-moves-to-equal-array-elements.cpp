class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minElem = *min_element(nums.begin(), nums.end());
        int result = 0;
        for(int num : nums) {
            result += num - minElem;
        }
        return result;
    }
};

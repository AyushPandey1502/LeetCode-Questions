class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long result = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            auto up = upper_bound(nums.begin()+i+1, nums.end(), upper-nums[i]);
            auto low = lower_bound(nums.begin()+i+1, nums.end(), lower-nums[i]);
            result += (up-low);
        }
        return result;
    }
};
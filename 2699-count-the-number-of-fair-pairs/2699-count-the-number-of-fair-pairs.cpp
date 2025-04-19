class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        auto solve = [&](int target){
            long long result = 0;
            int low = 0, high = nums.size()-1;
            while(low < high){
                int sum = nums[low]+nums[high];
                if(sum <= target){
                    result += (high-low);
                    low++;
                }else high--;
            }
            return result;
        };
        return solve(upper) - solve(lower-1);
    }
};
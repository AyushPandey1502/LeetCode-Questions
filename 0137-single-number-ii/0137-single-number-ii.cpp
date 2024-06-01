// Time Complexity : O( nlogn + n/3)
// Space Complexity : O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 3) {
            if(nums[i] != nums[i-1]) return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int result = INT_MIN, n = nums.size();
        for(int i = 0; i < n; i++){
            result = max(result, abs(nums[i]-nums[(i+1)%n]));
        }
        return result;
    }
};
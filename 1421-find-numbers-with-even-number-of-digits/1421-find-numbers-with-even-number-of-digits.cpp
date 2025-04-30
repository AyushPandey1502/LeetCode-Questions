class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            result += (to_string(nums[i]).size() % 2 ? 0 : 1);
        }
        return result;
    }
};
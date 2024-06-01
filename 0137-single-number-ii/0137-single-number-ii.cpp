// Time Complexity : O(32 x n)
// Space Complexity : O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int bit = 0; bit < 32; bit++){
            int count = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] & (1 << bit)) count++;
            }
            if(count % 3 == 1) result = result | (1 << bit);
        }
        return result;
    }
};
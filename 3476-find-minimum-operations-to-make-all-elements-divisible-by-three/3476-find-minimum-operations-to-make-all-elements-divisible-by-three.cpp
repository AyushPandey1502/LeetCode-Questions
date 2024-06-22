class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            int remainder = nums[i] % 3;
            if(remainder == 0) continue;
            else count++;
        }
        return count;
    }
};
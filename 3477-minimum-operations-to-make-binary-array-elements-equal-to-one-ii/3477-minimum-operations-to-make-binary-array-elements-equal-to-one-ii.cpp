class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if(flag == true){
                nums[i] = 1 - nums[i];
            }
            if (nums[i] == 0) {
                count++;
                flag = !flag;
            }
        }
        return count;
    }
};
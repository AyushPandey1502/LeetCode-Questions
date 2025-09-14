class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        while(i < n){
            while(i < n && nums[i] == 0) i++;
            if(i == n) break;
            nums[j++] = nums[i++];
        }
        while(j < n) nums[j++] = 0;
    }
};
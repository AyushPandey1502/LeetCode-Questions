class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            if(nums[i] == nums[i+1]){
                nums[i] <<= 1;
                nums[i+1] = 0;
            }
        }
        vector<int> result(n, 0);
        int k = 0;
        for(auto it : nums){
            if(it != 0) result[k++] = it;
        }
        return result;
    }
};
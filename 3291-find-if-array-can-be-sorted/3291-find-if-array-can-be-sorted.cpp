class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n-i-1; j++){
                if(nums[j] > nums[j + 1]){
                    int bits1 = __builtin_popcount(nums[j]);
                    int bits2 = __builtin_popcount(nums[j+1]);
                    if(bits1 != bits2) return false;
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        return true;
    }
};
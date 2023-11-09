class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int count = 0;
        int size = nums.size();
        for(int i = 0; i < size; i++){
            for(int j = i+1; j < size; j++){
                if((nums[j] - nums[i]) == diff){
                    for(int k = j+1; k < size; k++){
                        if((nums[k] - nums[j]) == diff) count++;
                    }
                }
            }
        }
        return count;
    }
};
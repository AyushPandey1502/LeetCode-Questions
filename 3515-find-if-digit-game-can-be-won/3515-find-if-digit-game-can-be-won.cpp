class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int oneDigSum = 0;
        int twoDigSum = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 9){
                oneDigSum += nums[i];
            }else{
                twoDigSum += nums[i];
            }
        }
        return (oneDigSum == twoDigSum) ? false : true;
    }
};
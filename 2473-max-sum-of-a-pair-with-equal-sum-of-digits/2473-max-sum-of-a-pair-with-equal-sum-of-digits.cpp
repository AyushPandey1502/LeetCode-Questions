class Solution {
public:
    int digitSum(int num){
        int result = 0;
        while(num > 0){
            result += num % 10;
            num /= 10;
        }
        return result;
    }

    int maximumSum(vector<int>& nums) {
        int result = -1;
        vector<int> dig(82, -1);
        for(int i = 0; i < nums.size(); i++){
            int digSum = digitSum(nums[i]);
            if(dig[digSum] != -1){
                result = max(result, nums[i] + dig[digSum]);
                dig[digSum] = max(dig[digSum], nums[i]);
            }else dig[digSum] = nums[i];
        }
        return result;
    }
};
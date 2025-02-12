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
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            int digSum = digitSum(nums[i]);
            if(map.count(digSum)){
                result = max(result, nums[i] + map[digSum]);
                map[digSum] = max(map[digSum], nums[i]);
            }else map[digSum] = nums[i];
        }
        return result;
    }
};
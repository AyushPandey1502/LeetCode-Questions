class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> posNum, negNum;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) posNum.push_back(nums[i]);
            else negNum.push_back(nums[i]);
        }
        vector<int> result;
        for(int i = 0; i < n/2; i++){
            result.push_back(posNum[i]);
            result.push_back(negNum[i]);
        }
        return result;
    }
};
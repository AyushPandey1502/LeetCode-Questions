class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> posNum, negNum;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                posNum.push_back(nums[i]);
            else
                negNum.push_back(nums[i]);
        }
        vector<int> result(n);
        for (int i = 0; i < n / 2; i++) {
            result[2 * i] = (posNum[i]);
            result[2 * i + 1] = (negNum[i]);
        }
        return result;
    }
};
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> answer(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int leftSum = 0;
            int rightSum = 0;
            for (int j = 0; j < i; j++) {
                leftSum += nums[j];
            }
            for (int k = i + 1; k < nums.size(); k++) {
                rightSum += nums[k];
            }
            answer[i] = abs(leftSum - rightSum);
        }

        return answer;
    }
};

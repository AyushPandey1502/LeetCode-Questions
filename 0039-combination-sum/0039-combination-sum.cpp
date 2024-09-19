class Solution {
public:
    void generateComb(int i, vector<int> nums, int target, int sum,
                      vector<int> temp, vector<vector<int>>& result) {
        if (i == nums.size()) {
            if (sum == target) {
                result.push_back(temp);
            }
            return;
        }
        if(sum > target) return;
        temp.push_back(nums[i]);
        generateComb(i, nums, target, sum + nums[i], temp, result);
        temp.pop_back();
        generateComb(i + 1, nums, target, sum, temp, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> result;
        generateComb(0, candidates, target, 0, temp, result);
        return result;
    }
};
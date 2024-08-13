class Solution {
public:
    vector<vector<int>> result;
    
    void solve(vector<int>& nums, int index, int sum, vector<int>& temp) {
        if (sum == 0) {
            result.push_back(temp);
            return;
        }

        if (sum < 0 || index < 0) {
            return;
        }

        solve(nums, index - 1, sum, temp);
        temp.push_back(nums[index]);
        solve(nums, index, sum - nums[index], temp);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        solve(candidates, candidates.size() - 1, target, temp);
        return result;
    }
};

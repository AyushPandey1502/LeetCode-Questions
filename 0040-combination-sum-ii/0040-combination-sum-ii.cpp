class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& nums, int index, int sum, vector<int>& temp) {
        if (sum == 0) {
            result.push_back(temp);
            return;
        }

        for (int i = index; i >= 0; i--) {
            if (i < index && nums[i] == nums[i + 1]) continue; 
            if (nums[i] > sum) continue; 

            temp.push_back(nums[i]);
            solve(nums, i - 1, sum - nums[i], temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); 
        vector<int> temp;
        solve(candidates, candidates.size() - 1, target, temp);
        return result;
    }
};

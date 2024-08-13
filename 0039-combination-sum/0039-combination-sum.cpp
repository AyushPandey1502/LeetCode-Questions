class Solution {
public:
    vector<vector<int>> result;
    void solve(int index, vector<int> nums, vector<int>& temp, int sum, int n){
        if(sum == 0){
            result.push_back(temp);
            return;
        }
        if(sum < 0 || index == n || index < 0) return;

        solve(index + 1, nums, temp, sum, n);
        temp.push_back(nums[index]);
        solve(index, nums, temp, sum - nums[index], n);
        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        int n = candidates.size();
        solve(0, candidates, temp, target, n);
        return result;
    }
};
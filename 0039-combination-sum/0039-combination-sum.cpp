class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& candidates, int index, int target, vector<int>& temp) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        if (target < 0) {
            return;
        }
        
        for (int i = index; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            solve(candidates, i, target - candidates[i], temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        vector<int> temp;
        solve(candidates, 0, target, temp);
        return result;
    }
};

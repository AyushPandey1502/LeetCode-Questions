class Solution {
public:
    void generateComb(int i, vector<int>& nums, int target, vector<int> temp, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(temp);
            return;
        }
        if (target < 0 || i == nums.size()) return;
        temp.push_back(nums[i]);
        generateComb(i + 1, nums, target - nums[i], temp, result);
        temp.pop_back();

        for(int j = i + 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                generateComb(j, nums, target, temp, result);
                break;
            }
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        generateComb(0, candidates, target, temp, result);
        return result;
    }
};
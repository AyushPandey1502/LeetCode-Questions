class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> taken(nums.size(), false);
        vector<int> temp;
        findPerm(nums, temp, taken, result);
        return result;
    }

private:
    void findPerm(vector<int>& nums, vector<int>& temp, vector<bool>& taken, vector<vector<int>>& result) {
        if(temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(!taken[i]) {
                temp.push_back(nums[i]);
                taken[i] = true;
                findPerm(nums, temp, taken, result);
                temp.pop_back();
                taken[i] = false;
            }
        }
    }
};

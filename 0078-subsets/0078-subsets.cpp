class Solution {
public:
    void generate(int i, vector<int> nums, vector<int> temp, vector<vector<int>>& result){
        if(i == nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        generate(i + 1, nums, temp, result);
        temp.pop_back();
        generate(i + 1, nums, temp, result);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        generate(0, nums, temp, result);
        return result;
    }
};
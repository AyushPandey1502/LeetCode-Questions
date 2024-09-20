class Solution {
public:
    void generateComb(int i, vector<int> nums, vector<int> temp, vector<vector<int>>& result){
        if(i == nums.size()){
            result.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        generateComb(i + 1, nums, temp, result);
        temp.pop_back();

        for(int j = i + 1; j < nums.size(); j++){
            if(nums[j] != nums[i]){
                generateComb(j, nums, temp, result);
                return;
            }
        }
        generateComb(nums.size(), nums, temp, result);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        generateComb(0, nums, temp, result);
        return result;
    }
};
class Solution {
public:
    void generateComb(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
        result.push_back(temp);
        
        for (int j = i; j < nums.size(); ++j) {
            if (j > i && nums[j] == nums[j - 1]) {
                continue;  
            }
            temp.push_back(nums[j]);
            generateComb(j + 1, nums, temp, result); 
            temp.pop_back(); 
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());  
        generateComb(0, nums, temp, result);
        return result;
    }
};

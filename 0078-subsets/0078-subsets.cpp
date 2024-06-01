// BIT MANIPULATION METHOD
// Time Complexity: O(2^n * n)
// Space Complexity : O(2^n * n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        int numSubsets = 1 << n;
        for(int i = 0; i < numSubsets; i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                if((1 << j) & i) temp.push_back(nums[j]);
            }
            result.push_back(temp);
        }
        return result;
    }
};
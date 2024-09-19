class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        int count = 1 << n; 
        
        for(int i = 0; i < count; i++){
            vector<int> temp;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)) { 
                    temp.push_back(nums[j]);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};

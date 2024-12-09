class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1];
            if(nums[i - 1] % 2 == 0 && nums[i] % 2 == 0) prefix[i]++;
            if(nums[i - 1] % 2 != 0 && nums[i] % 2 != 0) prefix[i]++;
        }
        vector<bool> result; 
        for (auto it : queries) {
            int left = it[0], right = it[1];
            int count = prefix[right] - (left > 0 ? prefix[left] : 0);
            result.push_back(count == 0);
        }
        return result; 
    }
};
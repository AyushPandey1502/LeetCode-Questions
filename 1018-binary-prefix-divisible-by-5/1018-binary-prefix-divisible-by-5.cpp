class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size(), num = 0;
        vector<bool> result(n);
        for(int i = 0; i < n; i++){
            num = (2 * num + nums[i]) % 5;
            result[i] = (num == 0);
        }
        return result;
    }
};
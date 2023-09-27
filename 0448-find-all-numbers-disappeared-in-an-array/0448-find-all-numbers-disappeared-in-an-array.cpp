class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0); 
        for (int num : nums) {
            ans[num - 1] = 1; 
        }

        vector<int> missing;

        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) {
                missing.push_back(i + 1);
            }
        }
        return missing;
    }
};

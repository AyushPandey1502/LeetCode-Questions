class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), suffix(n);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                prefix[i] = nums[i];
                suffix[n-1] = nums[n-1];  
            } else {
                prefix[i] = max(nums[i], prefix[i-1]);
                suffix[n-i-1] = min(nums[n-i-1], suffix[n-i]); 
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (prefix[i] <= suffix[i + 1]) return i + 1;
        }

        return -1; 
    }
};

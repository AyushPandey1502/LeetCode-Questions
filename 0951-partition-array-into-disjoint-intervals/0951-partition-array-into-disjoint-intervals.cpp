class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n);

        for (int i = 0; i < n; i++) {
            if (i == 0) suffix[n-1] = nums[n-1];  
            else suffix[n-i-1] = min(nums[n-i-1], suffix[n-i]); 
        }

        int maxLeft = nums[0];
        for (int i = 1; i < n; i++) {
            maxLeft = max(maxLeft, nums[i-1]);
            if (maxLeft <= suffix[i]) return i;
        }

        return -1; 
    }
};

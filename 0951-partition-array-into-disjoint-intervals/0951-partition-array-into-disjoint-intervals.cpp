class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffix(n);

        for (int i = 0; i < n; i++) {
            if (i == 0) suffix[n-1] = nums[n-1];  
            else suffix[n-i-1] = min(nums[n-i-1], suffix[n-i]); 
        }

        int maxLeft = -1;
        for (int i = 0; i < n-1; i++) {
            maxLeft = max(maxLeft, nums[i]);
            if (maxLeft <= suffix[i+1]) return i+1;
        }

        return -1; 
    }
};

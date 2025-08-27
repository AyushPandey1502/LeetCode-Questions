class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), parent(n);
        sort(nums.begin(), nums.end());
        int maxLen = 1, index = 0;
        for(int i = 0; i < n; i++){
            parent[i] = i;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if(maxLen < dp[i]){
                maxLen = dp[i];
                index = i;
            }
        }
        vector<int> result;
        while (parent[index] != index) {
            result.push_back(nums[index]);
            index = parent[index];
        }
        result.push_back(nums[index]);
        reverse(result.begin(), result.end());
        return result;
    }
};
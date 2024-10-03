class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        int rem = totalSum % p;
        if (rem == 0) return 0;
        
        unordered_map<int, int> prefixMap;
        prefixMap[0] = -1;
        long long prefixSum = 0;
        int minLen = n;
        
        for (int i = 0; i < n; ++i) {
            prefixSum = (prefixSum + nums[i]) % p;
            int target = (prefixSum - rem + p) % p;
            if (prefixMap.find(target) != prefixMap.end()) {
                minLen = min(minLen, i - prefixMap[target]);
            }
            prefixMap[prefixSum] = i;
        }
        
        return minLen == n ? -1 : minLen;
    }
};

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> set(nums.begin(), nums.end());
        int count = set.size();

        int result = 0;
        unordered_map<int, int> freq;
        int left = 0;

        for (int right = 0; right < n; right++) {
            freq[nums[right]]++;
            while (freq.size() == count) {
                result += n - right; 
                if(--freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }
        }
        return result;
    }
};

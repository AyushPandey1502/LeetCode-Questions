class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
        int left = 0, right = 0, count = 0;
        unordered_map<int, int> freq;
        
        while (right < nums.size()) {
            if (freq[nums[right]] == 0) {
                k--;
            }
            freq[nums[right]]++;
            right++;
            
            while (k < 0) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) {
                    k++;
                }
                left++;
            }
            count += (right - left);
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
};

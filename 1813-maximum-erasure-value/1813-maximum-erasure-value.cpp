class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int result = 0, n = nums.size();
        int left = 0, right = 0, sum = 0;
        unordered_map<int, int> freq;
        while(right < n){
            freq[nums[right]]++;
            sum += nums[right];
            while(freq[nums[right]] > 1){
                freq[nums[left]]--;
                sum -= nums[left++];
            }
            result = max(result, sum);
            right++;
        }
        return result;
    }
};
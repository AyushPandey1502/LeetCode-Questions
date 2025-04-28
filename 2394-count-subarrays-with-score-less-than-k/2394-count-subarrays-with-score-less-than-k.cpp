class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long result = 0, sum = 0;
        int n = nums.size(), left = 0;
        for(int right = 0; right < n; right++){
            sum += nums[right];
            while(left <= right && sum * (right - left + 1) >= k){
                sum -= nums[left++];
            }
            result += (right - left + 1);
        }
        return result;
    }
};
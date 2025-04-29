class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result = 0;
        int maxElem = *max_element(nums.begin(), nums.end());
        int left = 0, right = 0, n = nums.size();
        unordered_map<int, int> map;
        while(right < n){
            map[nums[right]]++;
            while(map[maxElem] >= k){
                result += (n - right);
                if(--map[nums[left]] == 0) map.erase(nums[left]);
                left++;
            }
            right++;
        }
        return result;
    }
};
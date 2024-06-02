// Similar to Prefix Sum Method 
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int count = 0;
        map[0]++;
        int diff = 0;
        bool found = false;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > k) diff++;
            else if(nums[i] < k) diff--;
            else found = true;

            if(found) count += map[diff] + map[diff-1];
            else map[diff]++;
        }
        return count;
    }
};
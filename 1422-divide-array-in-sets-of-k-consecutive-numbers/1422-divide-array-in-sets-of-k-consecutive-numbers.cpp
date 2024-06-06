class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> map;
        for(auto x : nums) map[x]++;
        for(auto x : nums){
            if(map[x] == 0) continue;
            for(int i = 0; i < k; i++){
                if(map[x + i] == 0) return false;
                map[x + i]--;
            }
        }
        return true;
    }
};
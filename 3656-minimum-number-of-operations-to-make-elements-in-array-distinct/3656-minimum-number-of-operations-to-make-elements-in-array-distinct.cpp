class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = nums.size()-1; i >= 0; i--){
            if(map.count(nums[i])) return i / 3 + 1;
            map[nums[i]]++;
        }
        return 0;
    }
};
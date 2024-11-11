class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            unordered_set<int> seen;
            for(int j = i+1; j < n; j++){
                int comp = -(nums[i] + nums[j]);
                if(seen.find(comp) != seen.end()){
                    result.push_back({nums[i], nums[j], comp});
                    while(j+1 < n && nums[j] == nums[j+1]) j++;
                }
                seen.insert(nums[j]);
            }
        }
        return result;
    }
};
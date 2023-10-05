class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        set<int> set(nums.begin(), nums.end());
        for(auto x : set)
            if(count(nums.begin(), nums.end(), x) > (n/3)) result.push_back(x);
        return result;
    }
};

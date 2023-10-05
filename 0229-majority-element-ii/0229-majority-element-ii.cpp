class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        set<int> set(nums.begin(), nums.end());
        for(auto x : set)
            if(count(nums.begin(), nums.end(), x) > (nums.size()/3)) result.push_back(x);
        return result;
    }
};

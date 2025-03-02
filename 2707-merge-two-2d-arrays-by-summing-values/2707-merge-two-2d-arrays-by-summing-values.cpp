class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        map<int, int> map;
        for(auto it : nums1) map[it[0]] += it[1];
        for(auto it : nums2) map[it[0]] += it[1];
        for(auto it : map) result.push_back({it.first, it.second});
        return result;
    }
};
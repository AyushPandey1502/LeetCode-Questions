class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result;
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        set<int> diff1, diff2;

        set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(),
                       inserter(diff1, diff1.begin()));
        set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(),
                       inserter(diff2, diff2.begin()));
        result.push_back(vector<int>(diff1.begin(), diff1.end()));
        result.push_back(vector<int>(diff2.begin(), diff2.end()));
        return result;
    }
};
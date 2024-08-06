class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end()),
            set2(nums2.begin(), nums2.end());
        vector<int> result;
        for(auto it : set2){
            if(set1.find(it) != set1.end()){
                result.push_back(it);
            }
        }
        return result;
    }
};
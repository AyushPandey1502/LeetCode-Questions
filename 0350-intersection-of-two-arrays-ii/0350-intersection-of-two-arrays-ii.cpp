class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {       
        unordered_map<int, int> frequency;

        vector<int> result;
        for (const auto& num : nums1) {
            frequency[num]++;
        }
        for (const auto& num : nums2) {
            if (frequency[num] > 0) {
                result.push_back(num);
                frequency[num]--;
            }
        }
        return result;
    }
};
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> countMap; 
        vector<int> result;
        for (int num : nums) {
            countMap[num]++;
        }
        for (auto pair : countMap) {
            if (pair.second > (nums.size() / 3)) {
                result.push_back(pair.first);
            }
        }
        return result;
    }
};

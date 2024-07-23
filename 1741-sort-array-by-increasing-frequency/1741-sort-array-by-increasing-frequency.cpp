class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        vector<pair<int, int>> freqPairs;
        for (auto it : freq) {
            freqPairs.push_back({it.second, it.first});
        }
        sort(freqPairs.begin(), freqPairs.end(),
             [](pair<int, int>& a, pair<int, int>& b) {
                 if (a.first == b.first)
                     return a.second > b.second;
                 return a.first < b.first;
             });
        vector<int> sortedNums;
        for (auto it : freqPairs) {
            sortedNums.insert(sortedNums.end(), it.first, it.second);
        }
        return sortedNums;
    }
};

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }
        
        vector<pair<int, int>> elements;
        for(auto it : freq){
            elements.push_back({it.second, it.first});
        }
        
        sort(elements.begin(), elements.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });
        
        vector<int> sortedNums;
        for(auto it : elements){
            sortedNums.insert(sortedNums.end(), it.first, it.second);
        }
        
        return sortedNums;
    }
};

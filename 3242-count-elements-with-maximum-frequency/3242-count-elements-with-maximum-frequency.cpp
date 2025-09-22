class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxFreq = 0, result = 0;
        unordered_map<int ,int> mp;
        for(auto it : nums) maxFreq = max(maxFreq, ++mp[it]);
        for(auto it : mp){
            if(it.second == maxFreq) result += it.second;
        }
        return result;
    }
};
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto it : nums) freq[it]++;
        vector<int> result;
        for(auto it : freq){
            if(it.second == 2) result.push_back(it.first);
        }
        return result;
    }
};
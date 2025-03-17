class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int it : nums) freq[it]++;
        for(auto it : freq){
            if(it.second % 2 == 1) return false;
        }
        return true;
    }
};
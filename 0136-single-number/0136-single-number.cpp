class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        int result;
        for(int num : nums) map[num]++;
        for(auto it : map){
            if(it.second == 1) result = it.first;
        }
        return result;
    }
};
class Solution {
public:
    int numRabbits(vector<int>& nums) {
        unordered_map <int,int> map;
        for (int it : nums) map[it]++;
        int result = 0;
        for (auto it : map){
            result += ceil((double)it.second / (it.first + 1)) * (it.first + 1);
        }
        return result;
    }
};
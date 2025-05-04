class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> map;
        int result = 0;

        for (auto& d : dominoes) {
            int key = min(d[0], d[1]) * 10 + max(d[0], d[1]);
            result += map[key]++;
        }
        return result;
    }
};

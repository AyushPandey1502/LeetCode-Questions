class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> mappedNums(n);
        for (int i = 0; i < n; i++) {
            string num = to_string(nums[i]);
            int mapNum = 0;
            for (auto dig : num) {
                mapNum = mapNum * 10 + mapping[dig - '0'];
            }
            mappedNums[i] = {mapNum, i};
        }
        sort(mappedNums.begin(), mappedNums.end(),
             [&](const pair<int, int> a, const pair<int, int> b) {
                 return a.first < b.first ||
                        (a.first == b.first && a.second < b.second);
             });
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            result[i] = nums[mappedNums[i].second];
        }
        return result;
    }
};
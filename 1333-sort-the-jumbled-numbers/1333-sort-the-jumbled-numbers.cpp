class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> mappedNums(n);

        for (int i = 0; i < n; i++) {
            int original = nums[i];
            int mappedValue = 0, place = 1;

            if (original == 0) {
                mappedValue = mapping[0];
            } else {
                while (original > 0) {
                    int digit = original % 10;
                    mappedValue = mapping[digit] * place + mappedValue;
                    original /= 10;
                    place *= 10;
                }
            }

            mappedNums[i] = {mappedValue, i};
        }

        sort(mappedNums.begin(), mappedNums.end(),
             [&](const pair<int, int>& a, const pair<int, int>& b) {
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

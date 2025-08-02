class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mpp;
        for (int b : basket1) mpp[b]++;
        for (int b : basket2) mpp[b]--;

        int minElem = INT_MAX;
        vector<int> temp;

        for (auto& [u, v] : mpp) {
            if (v % 2 == 1) return -1;
            for (int i = 0; i < abs(v) / 2; i++)
                temp.push_back(u);
            minElem = min(minElem, u);
        }
        sort(temp.begin(), temp.end());

        long long result = 0;
        for (int i = 0; i < temp.size() / 2; i++) {
            result += min(temp[i], 2 * minElem);
        }
        return result;
    }
};
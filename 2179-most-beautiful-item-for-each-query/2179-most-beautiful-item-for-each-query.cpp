class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());
        vector<int> beauty(n);
        beauty[0] = items[0][1];
        for (int i = 1; i < n; i++) {
            beauty[i] = max(beauty[i - 1], items[i][1]);
        }
        vector<int> result;
        for (int query : queries) {
            int idx = upper_bound(items.begin(), items.end(), vector<int>{query, INT_MAX}) - items.begin() - 1;
            if (idx >= 0) {
                result.push_back(beauty[idx]);
            } else {
                result.push_back(0);
            }
        }
        return result;
    }
};

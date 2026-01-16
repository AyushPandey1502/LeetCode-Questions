class Solution {
    const int MOD = 1e9 + 7;
    unordered_set<int> getEdges(vector<int>& fences, int border) {
        unordered_set<int> st;
        fences.push_back(1);
        fences.push_back(border);
        sort(fences.begin(), fences.end());
        for (int i = 0; i < fences.size(); i++) {
            for (int j = i + 1; j < fences.size(); j++) {
                st.insert(fences[j] - fences[i]);
            }
        }
        return st;
    }

public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        auto hEdges = getEdges(hFences, m);
        auto vEdges = getEdges(vFences, n);
        int result = 0;
        for (auto it : hEdges) {
            if (vEdges.contains(it)) result = max(result, it);
        }
        if (result == 0) result = -1;
        else result = 1ll * result * result % MOD;
        return result;
    }
};
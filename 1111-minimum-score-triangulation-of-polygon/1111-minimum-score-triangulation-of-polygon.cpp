class Solution {
public:
    int n;
    vector<int> vals;
    unordered_map<int, int> memo;

    int computeMinScore(int i, int j) {
        if (i + 2 > j) return 0;
        if (i + 2 == j) return vals[i] * vals[i + 1] * vals[j];

        int key = i * n + j;
        if (memo.count(key)) return memo[key];

        int minScore = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            minScore = min(minScore, vals[i] * vals[k] * vals[j] + computeMinScore(i, k) + computeMinScore(k, j));
        }
        return memo[key] = minScore;
    }

    int minScoreTriangulation(vector<int>& values) {
        vals = values;
        n = values.size();
        memo.clear();
        return computeMinScore(0, n - 1);
    }
};

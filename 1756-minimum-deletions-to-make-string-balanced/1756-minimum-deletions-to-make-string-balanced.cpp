class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> countB(n + 1, 0);
        vector<int> countA(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            countB[i + 1] = countB[i] + (s[i] == 'b' ? 1 : 0);
        }

        for (int i = n - 1; i >= 0; --i) {
            countA[i] = countA[i + 1] + (s[i] == 'a' ? 1 : 0);
        }

        int minDeletions = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            minDeletions = min(minDeletions, countB[i] + countA[i]);
        }

        return minDeletions;
    }
};

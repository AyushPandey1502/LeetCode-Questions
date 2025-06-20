class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        int maxInd = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i], words[j]) == 1 && dp[j] + 1 > dp[i] &&
                    groups[i] != groups[j]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[maxInd]) maxInd = i;
        }

        vector<string> result;
        for (int i = maxInd; i >= 0; i = prev[i]) {
            result.emplace_back(words[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool check(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            diff += s1[i] != s2[i];
            if (diff > 1) return false;
        }
        return diff == 1;
    }
};
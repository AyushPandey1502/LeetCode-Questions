class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int maxLen = -1;
        for (int len = 1; len <= n; ++len) {
            unordered_map<string, int> freq;
            for (int i = 0; i <= n - len; ++i) {
                string sub = s.substr(i, len);
                if (allSame(sub)) {
                    freq[sub]++;
                    if (freq[sub] >= 3) {
                        maxLen = max(maxLen, len);
                    }
                }
            }
        }
        return maxLen;
    }

    bool allSame(string s) {
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[0]) {
                return false;
            }
        }
        return true;
    }
};

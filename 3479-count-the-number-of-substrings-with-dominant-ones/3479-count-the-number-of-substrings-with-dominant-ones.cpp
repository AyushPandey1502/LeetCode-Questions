class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pos(n + 1);
        pos[0] = -1;
        for (int i = 0; i < n; i++) {
            if (i == 0 || (i > 0 && s[i - 1] == '0')) pos[i + 1] = i;
            else pos[i + 1] = pos[i];
        }
        int result = 0;
        for (int i = 1; i <= n; i++) {
            int cnt0 = s[i - 1] == '0';
            int j = i;
            while (j > 0 && cnt0 * cnt0 <= n) {
                int cnt1 = (i - pos[j]) - cnt0;
                if (cnt0 * cnt0 <= cnt1) {
                    result += min(j - pos[j], cnt1 - cnt0 * cnt0 + 1);
                }
                j = pos[j];
                cnt0++;
            }
        }
        return result;
    }
};
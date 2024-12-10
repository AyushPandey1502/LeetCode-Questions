class Solution {
public:
    int maximumLength(string s) {
        int n = s.size(), low = 1, high = n, maxLength = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (checkSubstring(s, mid)) {
                maxLength = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return maxLength;
    }

    bool checkSubstring(const string& s, int len) {
        unordered_map<string, int> freqMap;
        string window = s.substr(0, len);
        if (allSame(window)) freqMap[window]++;
        for (int i = len; i < s.size(); ++i) {
            window.erase(window.begin());
            window.push_back(s[i]);
            if (allSame(window)) freqMap[window]++;
            if (freqMap[window] >= 3) return true;
        }
        return false;
    }

    bool allSame(const string& s) {
        return all_of(s.begin(), s.end(), [&](char c) { return c == s[0]; });
    }
};

class Solution {
public:
    bool subsequence(const string &s, const string &p) {
        int i = 0, j = 0;
        while (i < s.size() && j < p.size()) {
            if (s[i] == p[j]) j++;
            i++;
        }
        return j == p.size();
    }

    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = s.size(), m = removable.size(), result = 0;
        int left = 0, right = m - 1;

        auto check = [&](int mid) {
            vector<bool> removed(n, false);
            for (int i = 0; i <= mid; i++) removed[removable[i]] = true;
            string modified;
            for (int i = 0; i < n; i++) {
                if (!removed[i]) modified += s[i];
            }
            return subsequence(modified, p);
        };

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                result = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
};

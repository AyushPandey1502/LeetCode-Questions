class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        return backtrack(s, 0, set);
    }

    int backtrack(string s, int start, unordered_set<string>& set) {
        if (start == s.size()) {
            return 0;
        }

        int maxSplits = 0;
        string curr = "";

        for (int i = start; i < s.size(); ++i) {
            curr += s[i];
            if (set.find(curr) == set.end()) {
                set.insert(curr);
                maxSplits = max(maxSplits, 1 + backtrack(s, i + 1, set));
                set.erase(curr); 
            }
        }
        return maxSplits;
    }
};

class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0, prev = 0, grp = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) grp++;
            else {
                prev = grp;
                grp = 1;
            }
            if (grp <= prev) result++;
        }
        return result;
    }
};

class Solution {
public:
    void reverseString(vector<char>& s, int pos = 0) {
        if (pos < s.size() / 2) {
            swap(s[pos], s[s.size() - 1 - pos]);
            reverseString(s, pos + 1);
        }
    }
};
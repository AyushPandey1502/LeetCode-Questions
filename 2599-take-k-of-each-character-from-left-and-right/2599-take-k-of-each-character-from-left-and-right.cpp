class Solution {
public:
    int takeCharacters(string s, int k) {
        vector<int> count(3, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        if (*min_element(count.begin(), count.end()) < k) {
            return -1;
        }
        int result = INT_MAX;
        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            count[s[r] - 'a']--;
            
            while (*min_element(count.begin(), count.end()) < k) {
                count[s[l] - 'a']++;
                l++;
            }
            result = min(result, static_cast<int>(s.length()) - (r - l + 1));
        }
        return result;
    }
};
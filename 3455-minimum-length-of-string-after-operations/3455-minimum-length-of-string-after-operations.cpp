class Solution {
public:
    int minimumLength(string s) {
        int result = s.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] >= 3) {
                result -= 2;
                freq[s[i] - 'a'] = 1;
            }
        }
        return result;
    }
};
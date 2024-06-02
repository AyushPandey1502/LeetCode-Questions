class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        bool found;
        int count = 0;
        do {
            found = false;
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    s[i] = '1';
                    s[i + 1] = '0';
                    i++;
                    found = true;
                }
            }
            if (found)
                count++;
        } while (found);
        return count;
    }
};
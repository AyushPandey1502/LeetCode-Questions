class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int count = 0;
        while (true) {
            bool found = false;
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] == '0' && s[i+1] == '1') {
                    swap(s[i], s[i+1]);
                    i++; 
                    found = true;
                }
            }
            if (!found) break;
            count++;
        }
        return count;
    }
};

class Solution {
public:
    int maxOperations(string s) {
        int count = 0, result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') {
                while ((i + 1) < s.length() && s[i + 1] == '0') i++;
                result += count;
            } else count++;
        }
        return result;
    }
};
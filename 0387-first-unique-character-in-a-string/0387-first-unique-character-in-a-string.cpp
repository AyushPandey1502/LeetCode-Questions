class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.length(); i++) {
            bool isUnique = true;
            for (int j = 0; j < s.length(); j++) {
                if (i!=j && s[i] == s[j]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                return i;
            }
        }
        return -1;
    }
};

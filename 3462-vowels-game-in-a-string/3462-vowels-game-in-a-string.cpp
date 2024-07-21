class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool doesAliceWin(string word) {
        int count = 0;
        for (char letter : word) {
            if (isVowel(letter)) {
                return true;
            }
        }
        return false;
    }
};
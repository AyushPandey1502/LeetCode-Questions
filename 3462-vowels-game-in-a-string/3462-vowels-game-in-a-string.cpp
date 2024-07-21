class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool doesAliceWin(string word) {
        for (char letter : word) {
            if (isVowel(letter)) {
                return true;
            }
        }
        return false;
    }
};
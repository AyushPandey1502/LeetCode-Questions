class Solution {
public:
    bool doesAliceWin(string s) {
        string vowel = "aeiou";
        for (auto it : s) {
            if (vowel.find(it) != string::npos) return true;
        }
        return false;
    }
};
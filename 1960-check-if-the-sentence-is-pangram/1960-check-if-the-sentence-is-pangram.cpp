class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> ascii(256, 0);
        for (char c : sentence) {
            ascii[c]++;
        }
        for (int i = 97; i <= 122; i++) {
            if (ascii[i] == 0) return false;
        }
        return true;
    }
};

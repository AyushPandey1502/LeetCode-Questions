class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int k = 0, n = str2.size();
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == str2[k] || (str1[i] - 'a' + 1) % 26 == (str2[k] - 'a')) k++;
            if (k == n) return true; 
        }
        return k == n;
    }
};
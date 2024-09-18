class Solution {
public:
    bool checkPalindrome(int left, int right, const string& s) {
        while (left < right) {
            if (!isalnum(s[left])) {
                ++left;
            } else if (!isalnum(s[right])) {
                --right;
            } else {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                ++left;
                --right;
            }
        }
        return true;
    }
    
    bool isPalindrome(string s) {
        return checkPalindrome(0, s.size() - 1, s);
    }
};

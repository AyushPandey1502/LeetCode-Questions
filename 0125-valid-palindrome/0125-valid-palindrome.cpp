class Solution {
public:
    bool checkPalindrome(int left, int right, const string& s) {
        if (left >= right) return true;
        if (!isalnum(s[left])) {
            return checkPalindrome(left + 1, right, s);
        }
        if (!isalnum(s[right])) {
            return checkPalindrome(left, right - 1, s);
        }
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        return checkPalindrome(left + 1, right - 1, s);
    }
    
    bool isPalindrome(string s) {
        return checkPalindrome(0, s.size() - 1, s);
    }
};

class Solution {
public:
    string largestOddNumber(string s) {
        int end = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] & 1) {
                end = i;
                break;
            }
        }
        if (end == -1) return "";
        string result = s.substr(0, end + 1);
        int i = 0;
        while (i < result.size() && result[i] == '0') i++;
        return (i == result.size()) ? "0" : result.substr(i);
    }
};
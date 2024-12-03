class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int k = 0, n = spaces.size();
        for (int i = 0; i < s.size(); i++) {
            if (k < n && i == spaces[k]) {
                result += ' ';
                k++;
            }
            result += s[i];
        }
        return result;
    }
};

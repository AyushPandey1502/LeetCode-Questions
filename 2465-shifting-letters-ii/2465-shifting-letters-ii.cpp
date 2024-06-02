// Similar to prefix Sum Approach
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shiftEffect(s.size() + 1, 0);
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2] == 1 ? 1 : -1;

            shiftEffect[start] += direction;
            shiftEffect[end + 1] -= direction;
        }
        int netShift = 0;
        for (int i = 0; i < s.size(); ++i) {
            netShift += shiftEffect[i];
            int newChar = ((s[i] - 'a' + netShift) % 26 + 26) % 26;
            s[i] = 'a' + newChar;
        }

        return s;
    }
};

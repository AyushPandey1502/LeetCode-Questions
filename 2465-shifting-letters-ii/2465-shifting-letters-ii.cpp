class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shiftAmount(s.size() + 1, 0);
        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2] == 1 ? 1 : -1;
            shiftAmount[start] += direction;
            if (end + 1 < s.size()) {
                shiftAmount[end + 1] -= direction;
            }
        }
        int netShift = 0;
        for (int i = 0; i < s.size(); ++i) {
            netShift += shiftAmount[i];
            int shiftValue = ((netShift % 26) + 26) % 26;
            s[i] = (s[i] - 'a' + shiftValue) % 26 + 'a';
        }
        return s;
    }
};

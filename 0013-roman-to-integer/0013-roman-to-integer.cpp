class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            int currentVal = roman[s[i]];

            if (i < s.size() - 1 && currentVal < roman[s[i + 1]]) {
                result -= currentVal;
            } else {
                result += currentVal;
            }
        }
        return result;
    }
};
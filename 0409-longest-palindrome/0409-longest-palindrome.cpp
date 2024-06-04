class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        for(auto ch : s) map[ch]++;
        int ones = 0, twos = 0;
        for(auto it : map){
            twos += it.second / 2;
            ones += it.second % 2;
        }
        return ones > 1 ? 2*twos + 1 : 2*twos + ones;
    }
};
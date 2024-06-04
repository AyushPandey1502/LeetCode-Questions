class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> map;
        int n = s.length();
        for(auto ch : s) map[ch]++;
        int oddFreq = 0;
        for(auto it : map){
            if(it.second % 2 == 1) oddFreq++;
        }
        return oddFreq > 0 ? n - oddFreq + 1 : n;
    }
};
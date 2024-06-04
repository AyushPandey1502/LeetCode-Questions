class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        int result = 0;
        
        for (auto word : words) {
            string wordRev = word;
            reverse(wordRev.begin(), wordRev.end());
            if (map[wordRev] > 0) {
                map[wordRev]--;
                result += 4;
            } else {
                map[word]++;
            }
        }
        for (auto it : map) {
            if (it.first[0] == it.first[1] && it.second > 0) {
                return result + 2;
            }
        }

        return result;
    }
};

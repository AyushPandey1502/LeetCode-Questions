class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> map;
        int n = words.size();
        bool flag = true;
        int count = 0;
        for (string s : words) map[s]++;
        for (int i = 0; i < n; i++) {
            if (map[words[i]]) {
                if (words[i][1] == words[i][0]) {
                    count += (map[words[i]] / 2) * 4;
                    if (map[words[i]] % 2 == 1) flag = false;
                } else {
                    string temp = "";
                    temp += words[i][1];
                    temp += words[i][0];
                    count += min(map[words[i]], map[temp]) * 4;
                    map[temp] = 0;
                }
                map[words[i]] = 0;
            }
        }
        if (!flag) count += 2;
        return count;
    }
};
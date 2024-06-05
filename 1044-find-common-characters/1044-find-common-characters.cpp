class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<vector<int>> wordFreq(words.size(), vector<int>(26, 0));
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                wordFreq[i][words[i][j] - 'a']++;
            }
        }

        vector<string> result;
        for (int i = 0; i < 26; i++) {
            int minCount = INT_MAX;
            for (int j = 0; j < wordFreq.size(); j++) {
                minCount = min(minCount, wordFreq[j][i]);
            }
            while (minCount > 0) {
                result.push_back(string(1, 'a' + i));
                minCount--;
            }
        }
        return result;
    }
};

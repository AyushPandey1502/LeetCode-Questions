class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_set<string> uniqueWords, repeatedWords;
        stringstream ss(s1 + " " + s2);
        string word;
        while (ss >> word) {
            if (uniqueWords.find(word) != uniqueWords.end()) {
                uniqueWords.erase(word);
                repeatedWords.insert(word);
            } else if (repeatedWords.find(word) == repeatedWords.end()) {
                uniqueWords.insert(word);
            }
        }
        return vector<string>(uniqueWords.begin(), uniqueWords.end());
    }
};

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        if (words1.size() < words2.size()) {
            swap(words1, words2);
        }
        int n = words1.size(), m = words2.size();
        int prefixMatch = 0, suffixMatch = 0;
        while (prefixMatch < m && words1[prefixMatch] == words2[prefixMatch]) {
            prefixMatch++;
        }
        while (suffixMatch < m && words1[n - 1 - suffixMatch] == words2[m - 1 - suffixMatch]) {
            suffixMatch++;
        }
        return (prefixMatch + suffixMatch >= m);
    }
    
    vector<string> split(string s) {
        vector<string> result;
        stringstream ss(s);
        string word;
        while (ss >> word) {
            result.push_back(word);
        }
        return result;
    }
};

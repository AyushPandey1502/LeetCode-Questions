class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word, result;

        stringstream ss(s);
        while(ss >> word) words.push_back(word);
        for(int i = words.size()-1; i >= 0; i--){
            result += words[i];
            if (i > 0) result += ' ';
        }
        return result;
    }
};
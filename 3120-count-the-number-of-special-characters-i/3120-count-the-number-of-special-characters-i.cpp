class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        vector<int> freqLowerCase(26, 0);
        vector<int> freqUpperCase(26, 0);
        for(int i = 0; i < word.size(); i++){
            if(word[i] >= 'A' && word[i] <= 'Z') freqUpperCase[word[i] - 'A']++;
            if(word[i] >= 'a' && word[i] <= 'z') freqLowerCase[word[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(freqLowerCase[i] && freqUpperCase[i]) count += 1;
        }
        return count;
    }
};
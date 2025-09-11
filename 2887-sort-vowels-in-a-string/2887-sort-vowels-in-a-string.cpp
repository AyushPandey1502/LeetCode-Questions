class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u');
    }

    string sortVowels(string s) {
        string result;
        vector<char> vowels;
        for(auto ch : s){
            if(isVowel(tolower(ch))) vowels.push_back(ch);
        }
        sort(vowels.begin(), vowels.end());
        int j = 0;
        for(int i = 0; i < s.size(); i++){
            if(!isVowel(tolower(s[i]))) result += s[i];
            else result += vowels[j++];
        }
        return result;
    }
};
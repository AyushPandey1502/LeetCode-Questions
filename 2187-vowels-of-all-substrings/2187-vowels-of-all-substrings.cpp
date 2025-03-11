class Solution {
public:
    long long countVowels(string word) {
        long long result = 0, count = 0;
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') count += i+1;
            result += count;
        }
        return result;
    }
};
class Solution {
public:
    long long countVowels(string word) {
        long long result = 0, n = word.size();
        for(int i = 0; i < word.size(); i++){
            char ch = word[i];
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                result += (n-i) * (i+1);
            }
        }
        return result;
    }
};
class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        string answer = "";
        vector<char> store;

        for(char ch : s){
            if(find(vowels.begin(), vowels.end(), ch) != vowels.end()) store.push_back(ch);
        }
        sort(store.begin(), store.end());

        int index = 0;
        for(char ch : s){
            if(find(vowels.begin(), vowels.end(), ch) != vowels.end()){
                answer += store[index++];
            }else answer += ch;
        }
        return answer;
    }
};
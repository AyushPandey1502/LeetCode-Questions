class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string sortVowels(string s) {
        priority_queue<char, vector<char>, greater<char>> pq;
        for(char ch : s){
            if(isVowel(ch)) pq.push(ch);
        }

        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                s[i] = pq.top();
                pq.pop();
            }
        }
        return s;
    }
};
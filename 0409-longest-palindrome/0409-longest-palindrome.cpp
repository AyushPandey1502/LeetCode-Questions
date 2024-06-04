class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<int> charSet;
        int count = 0;
        for(char ch : s){
            if(charSet.find(ch) != charSet.end()){
                charSet.erase(ch);
                count += 2;
            }else{
                charSet.insert(ch);
            }
        }
        return (charSet.empty()) ? count : count + 1;
    }
};
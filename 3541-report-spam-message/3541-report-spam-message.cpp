class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> set(bannedWords.begin(), bannedWords.end());
        int count = 0;
        for(auto it : message){
            if(set.find(it) != set.end()) count++;
            if(count == 2) return true;
        }
        return false;
    }
};
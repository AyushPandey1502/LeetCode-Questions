class Solution {
public:
    unordered_set<string> result;

    void backtrack(vector<int>& freq, string s){
        if(!s.empty()) result.insert(s);
        for(int i = 0; i < 26; i++){
            if(freq[i] > 0){
                freq[i]--;
                backtrack(freq, s + char(i + 'A'));
                freq[i]++;
            }
        }
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for(auto it : tiles) freq[it - 'A']++;
        backtrack(freq, "");
        return result.size();
    }
};
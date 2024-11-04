class Solution {
public:
    string compressedString(string word) {
        vector<pair<char, int>> result;
        int n = word.size(), count = 1;
        char lastChar = word[0];
        for(int i = 1; i < n; i++){
            if(word[i] != lastChar || count == 9){
                result.push_back({lastChar, count});
                lastChar = word[i];
                count = 1;
            }else{
                count++;
            }
        }
        string output = "";
        for(auto it : result) output += (to_string(it.second) + it.first);
        output += to_string(count) + lastChar;
        return output;
    }
};
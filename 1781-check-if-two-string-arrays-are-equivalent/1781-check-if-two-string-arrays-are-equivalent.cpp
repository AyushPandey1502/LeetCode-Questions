class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string string1, string2;
        for(string &wrd1 : word1){
            string1 += wrd1;
        }
        for(string &wrd2 : word2){
            string2 += wrd2;
        }
        return string1 == string2;
    }
};
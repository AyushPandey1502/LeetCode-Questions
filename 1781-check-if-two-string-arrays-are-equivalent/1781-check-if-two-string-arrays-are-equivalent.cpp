class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0;
        int index1 = 0, index2 = 0;

        while (i < word1.size() && j < word2.size()) {
            if (word1[i][index1] != word2[j][index2]) return false;

            index1++;
            index2++;

            if (index1 == word1[i].size()) {
                index1 = 0;
                i++;
            }
            if (index2 == word2[j].size()) {
                index2 = 0;
                j++;
            }
        }
        return i == word1.size() && j == word2.size();
    }
};

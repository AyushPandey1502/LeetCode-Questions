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
                i++;
                index1 = 0;
            }
            if (index2 == word2[j].size()) {
                j++;
                index2 = 0;
            }
        }

        return (i == word1.size()) && (j == word2.size());
    }
};

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> count;
        for (auto &ch : word) {
            count[ch]++;
        }
        int result = word.size();
        for (auto &[_, a] : count) {
            int deleted = 0;
            for (auto &[_, b] : count) {
                if (a > b) deleted += b;
                else if (b > a + k) deleted += b - (a + k);
            }
            result = min(result, deleted);
        }
        return result;
    }
};
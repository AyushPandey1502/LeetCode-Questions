class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        if(set.find(endWord) == set.end()) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        set.erase(beginWord);

        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (word == endWord)
                return steps;

            for (int i = 0; i < word.size(); i++) {
                int org = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (set.find(word) != set.end()) {
                        q.push({word, steps + 1});
                        set.erase(word);
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
};
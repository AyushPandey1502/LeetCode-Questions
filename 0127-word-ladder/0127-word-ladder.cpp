class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) return 0;

        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        unordered_set<string> visited;

        int length = 1;

        while (!beginSet.empty() && !endSet.empty()) {
            if (beginSet.size() > endSet.size()) swap(beginSet, endSet);
            unordered_set<string> next;
            for (auto word : beginSet) {
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char org = temp[i];
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        if (ch == org) continue;
                        temp[i] = ch;

                        if (endSet.find(temp) != endSet.end()) return length + 1;

                        if (words.find(temp) != words.end() && !visited.count(temp)) {
                            next.insert(temp);
                            visited.insert(temp);
                        }
                    }
                    temp[i] = org;
                }
            }
            beginSet = move(next);
            length++;
        }
        return 0;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end()) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int len = q.front().second;
            q.pop();
            for(int i = 0; i < word.size(); i++){
                char org = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(ch == org) continue;
                    word[i] = ch;
                    if(word == endWord) return len+1;
                    if(words.find(word) != words.end()){
                        q.push({word, len+1});
                        words.erase(word);
                    }
                }
                word[i] = org;
            }
        }
        return 0;
    }
};
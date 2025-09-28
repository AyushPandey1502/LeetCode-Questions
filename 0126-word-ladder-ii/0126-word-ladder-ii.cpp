class Solution {
public:
    void dfs(string word, string &beginWord, vector<string>& seq, unordered_map<string, int> &mpp, vector<vector<string>>& result){
        if(word == beginWord){
            reverse(seq.begin(), seq.end());
            result.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int step = mpp[word];
        for(int i = 0 ; i < word.size(); i++){
            char org = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(mpp.count(word) && mpp[word]+1 == step){
                    seq.push_back(word);
                    dfs(word, beginWord, seq, mpp, result);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int len = beginWord.size();
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return {};
        unordered_map<string, int> mpp;
        queue<string> q;
        q.push(beginWord);
        st.erase(beginWord);
        mpp[beginWord] = 1;

        while(!q.empty()){
            string word = q.front();
            int step = mpp[word];
            q.pop();

            for(int i = 0; i < word.size(); i++){
                char org = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    if(ch == org) continue;
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        mpp[word] = step+1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word[i] = org;
            }
        }
        vector<vector<string>> result;
        vector<string> seq = {endWord};
        dfs(endWord, beginWord, seq, mpp, result);
        return result;
    }
};
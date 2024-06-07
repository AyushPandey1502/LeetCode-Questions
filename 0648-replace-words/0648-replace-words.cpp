class Solution {
public:
    string findRoot(string word, unordered_set<string> &set){
        for(int l = 1; l <= word.size(); l++){
            string root = word.substr(0, l);
            if(set.count(root)) return root;
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> set(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word, result;
        while(getline(ss, word, ' ')){
            result += findRoot(word, set) + ' ';
        }
        result.pop_back();
        return result;
    }
};
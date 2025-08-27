// BETTER SOLUTION
// TIME COMPLEXITY: O(N*L*L)

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size(), result = 0;
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;

        for(auto word : words){
            dp[word] = 1;
            for(int i = 0; i < word.size(); i++){
                string pred = word.substr(0, i) + word.substr(i+1);
                if(dp.count(pred)) dp[word] = max(dp[word], 1+dp[pred]);
            }
            result = max(result, dp[word]);
        }
        return result;
    }
};

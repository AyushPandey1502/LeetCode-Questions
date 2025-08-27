// TIME COMPLEXITY: O(N*N*L)

class Solution {
public:
    bool checkPossible(string a, string b) {
        if(a.size() + 1 != b.size()) return false;
        int i = 0, j = 0;
        while(j < b.size()) {
            if(i < a.size() && a[i] == b[j]) i++;
            j++;
        }
        return i == a.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size(), result = 0;
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });
        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(checkPossible(words[j], words[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};

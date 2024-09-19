class Solution {
public:
    void generate(int x, int n, string str, int open, int close, vector<string>& result){
        if(x == 2 * n){
            if(open == close){
                result.push_back(str);
            }
            return;
        }
        if(close > open) return;
        if(open < n) generate(x + 1, n, str + "(", open + 1, close, result);
        generate(x + 1, n, str + ")", open, close + 1, result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(0, n, "", 0, 0, result);
        return result;
    }
};
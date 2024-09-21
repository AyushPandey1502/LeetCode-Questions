class Solution {
public:
    void dfs(int num, int n, vector<int>& result) {
        if (num > n) return;
        result.push_back(num);
        for (int i = 0; i < 10; i++) {
            dfs(num * 10 + i, n, result);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= 9; i++) {
            dfs(i, n, result);
        }
        return result;
    }
};

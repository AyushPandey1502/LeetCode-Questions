class Solution {
public:
    void generateComb(int i, int n, int k, vector<int>& temp, vector<vector<int>>& result) {
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }
        if (i > n) return;
        for (int j = i; j <= n; j++) {
            temp.push_back(j);
            generateComb(j + 1, n, k, temp, result);
            temp.pop_back(); 
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> result;
        generateComb(1, n, k, temp, result);
        return result;
    }
};

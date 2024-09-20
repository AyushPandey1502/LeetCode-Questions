class Solution {
public:
    void generateComb(int i, int k, int sum, int n, vector<int> temp, vector<vector<int>>& result){
        if(temp.size() == k){
            if(sum == n){
                result.push_back(temp);
                return;
            }
        }
        if(sum > n || i > n || i > 9) return;
        temp.push_back(i);
        generateComb(i + 1, k, sum + i, n, temp, result);
        temp.pop_back();
        generateComb(i + 1, k, sum, n, temp, result);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int>> result;
        generateComb(1, k, 0, n, temp, result);
        return result;
    }
};
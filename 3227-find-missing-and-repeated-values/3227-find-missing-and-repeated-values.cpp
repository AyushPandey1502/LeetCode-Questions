class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int num1 = -1, num2 = -1;
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) freq[grid[i][j]]++;
        }
        for(int i = 1; i <= n*n; i++){
            if(!freq.count(i)) num1 = i;
            if(freq[i] == 2) num2 = i;
        }
        return {num2, num1};
    }
};

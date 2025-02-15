class Solution {
public:
    
    bool checkWays(string sq, int num, int index, int currSum, vector<vector<int>>& memo) {
        if (index == sq.size()) return num == currSum;
        if (currSum > num) return false;
        
        if (memo[index][currSum] != -1) return memo[index][currSum];
        
        bool flag = false;
        for (int j = index; j < sq.size(); j++) {
            string sub = sq.substr(index, j - index + 1);
            int val = stoi(sub);
            if (checkWays(sq, num, j + 1, currSum + val, memo)) {
                return memo[index][currSum] = true;
            }
        }
        return memo[index][currSum] = false;
    }
    
    int punishmentNumber(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            vector<vector<int>> memo(to_string(sq).size(), vector<int>(i+1, -1));
            if (checkWays(to_string(sq), i, 0, 0, memo)) count += sq;
        }
        return count;
    }
};

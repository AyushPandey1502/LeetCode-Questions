class Solution {
public:
    unordered_map<string, bool> memo;
    
    bool checkWays(string sq, int num, int index, int currSum) {
        if (index == sq.size()) return num == currSum;
        if (currSum > num) return false;
        
        string key = to_string(index) + "," + to_string(currSum);
        if (memo.find(key) != memo.end()) return memo[key];
        
        bool flag = false;
        for (int j = index; j < sq.size(); j++) {
            string sub = sq.substr(index, j - index + 1);
            int val = stoi(sub);
            
            if (checkWays(sq, num, j + 1, currSum + val)) {
                return memo[key] = true;
            }
        }
        return memo[key] = false;
    }
    
    int punishmentNumber(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            memo.clear(); 
            if (checkWays(to_string(sq), i, 0, 0)) count += sq;
        }
        return count;
    }
};

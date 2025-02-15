class Solution {
public:
    bool checkWays(string sq, int num, int index, int currSum){
        if(index == sq.size()) return num == currSum;
        if(currSum > num) return false;
        bool flag = false;
        for(int j = index; j < sq.size(); j++){
            string sub = sq.substr(index, j-index+1);
            int val = stoi(sub);

            flag = flag || checkWays(sq, num, j+1, currSum+val);
            if(flag) return true;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++){
            int sq = i * i;
            if(checkWays(to_string(sq), i, 0, 0)) count += sq;
        }
        return count;
    }
};
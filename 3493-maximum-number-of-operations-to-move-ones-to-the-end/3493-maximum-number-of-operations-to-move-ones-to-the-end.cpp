class Solution {
public:
    int maxOperations(string s) {
        int result = 0;
        int ones = 0;
        bool check = false;
        
        for (char num : s) {
            if (num == '1') {
                ones++;
                check = true;
            } else if (check) {
                result += ones;
                check = false;
            }
        }
        return result;
    }
};
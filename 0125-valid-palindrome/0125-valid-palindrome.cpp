class Solution {
public:
    bool isPalindrome(string s) {
        string result = "";
        for(char it : s){
            if(isalnum(it)) result += tolower(it);
        }
        int n = result.size();
        for(int i = 0; i < n / 2; i++){
            if(result[i] != result[n - i - 1]){
                return false;
            }
        }
        return true;
    }
};